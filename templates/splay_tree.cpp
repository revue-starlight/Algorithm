#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

#define MAX 500100
int root=0,N,tot=0;

inline int read()
{
       register int x=0,t=1;
       register char ch=getchar();
       while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
       if(ch=='-'){t=-1;ch=getchar();}
       while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
       return x*t;
}

struct Node
{
       int ch[2];//子节点
       int ff;//父节点 
       int cnt;//数量
       int val;//值 
       int son;//儿子数量  
}t[MAX];

void push_up(int u)//计算儿子数 
{
       t[u].son=t[t[u].ch[0]].son+t[t[u].ch[1]].son+t[u].cnt;
}

void rotate(int x)//旋转 
{
       register int y=t[x].ff;
       register int z=t[y].ff;
       register int k=t[y].ch[1]==x;//x是y的左或右儿子
       t[z].ch[t[z].ch[1]==y]=x;  t[x].ff=z;
       t[y].ch[k]=t[x].ch[k^1];   t[t[x].ch[k^1]].ff=y;
       t[x].ch[k^1]=y;              t[y].ff=x;
       push_up(y);push_up(x);   
}

void Splay(int x,int goal)//把x节点旋转到目标位置
{
       while(t[x].ff!=goal)
       {
                 int y=t[x].ff;
                 int z=t[y].ff;
                 if(z!=goal)//旋转  
                    (t[y].ch[0]==x)^(t[z].ch[0]==y)?rotate(x):rotate(y);
                 rotate(x);
       }
       if(goal==0)
           root=x;//当前的根节点 
}

void insert(int x)//插入x
{
       int u=root,ff=0;
       while(u&&t[u].val!=x)
       {
                 ff=u;
                 u=t[u].ch[x>t[u].val];
       }
       if(u)//已经有这个数字了  
          t[u].cnt++;//计算数字个数 
       else//不存在这个数字，加入新的节点 
       {
                  u=++tot;//总的节点数
               if(ff)
                   t[ff].ch[x>t[ff].val]=u;
               t[tot].ch[0]=0;
               t[tot].ch[1]=0;
               t[tot].ff=ff;  t[tot].val=x;
               t[tot].cnt=1;  t[tot].son=1;
       }
       Splay(u,0);
}

void Find(int x)//查找x的位置 
{
       int u=root;
       if(!u)return;//不存在节点，无法查找排名
       while(t[u].ch[x>t[u].val]&&x!=t[u].val)//找到x所在的位置 
          u=t[u].ch[x>t[u].val]; 
       Splay(u,0);
       
}

int Next(int x,int f)//查找前驱/后继
{
       Find(x);//查找x的位置(Splay操作到根节点) 
       int u=root;
       if((t[u].val>x&&f)||(t[u].val<x&&!f))return u;//返回结果 
       u=t[u].ch[f];
       while(t[u].ch[f^1])u=t[u].ch[f^1];
       return u;
}

void Delete(int x)//删除x
{
       int last=Next(x,0);//查找前驱
       int next=Next(x,1);//查找后继
       Splay(last,0);Splay(next,last);
       int del=t[next].ch[0];
       if(t[del].cnt>1)
       {
                 t[del].cnt--;//存在多个这个数字，直接减去一个 
                 Splay(del,0);
       }
       else
          t[next].ch[0]=0;//清除掉节点 
}

int K_th(int x)//查找排名为x的值 
{
       int u=root;
       if(t[u].son<x)//不存在这么多个数 
          return false;
       while(2333)
       {
                int y=t[u].ch[0];
                if(x>t[y].son+t[u].cnt)//在排名在u的后面 
                {
                         x-=t[y].son+t[u].cnt;//直接减掉这么多
                     u=t[u].ch[1];//在右子树中继续找  
                }
                else
                   if(t[y].son>=x)//如果y的节点数多于x 
                       u=y;       //在左子树中继续查找
                else
                    return t[u].val;//否则找到了结果，直接返回 
       }
}
int main()
{
       insert(-2147483647);
       insert(+2147483647);
       N=read();
       while(N--)
       {
                 int opt=read();
                 if(opt==1)
                    insert(read());
                 else
                 if(opt==2)
                    Delete(read());
                 else
                 if(opt==3)
                 {
                      Find(read());
                      printf("%d\n",t[t[root].ch[0]].son);
                 }
                 else
                 if(opt==4)
                      printf("%d\n",K_th(read()+1));
                 else
                 if(opt==5)
                    printf("%d\n",t[Next(read(),0)].val);
                 else
                 if(opt==6)
                    printf("%d\n",t[Next(read(),1)].val);
       }
       return 0;
}