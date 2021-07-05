#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 8e4;
const int inf=0x3f3f3f3f;
const int mod=1e6;
struct Node{
    int val,ch[2],ff;
}t[N];
int root=0,tot,ans=0;
void rotate(int x){
    register int y=t[x].ff;
    register int z=t[y].ff;
    register int k=t[y].ch[1]==x; 
    t[z].ch[t[z].ch[1]==y]=x; t[x].ff=z;
    t[y].ch[k]=t[x].ch[k^1]; t[t[x].ch[k^1]].ff=y;
    t[x].ch[k^1]=y; t[y].ff=x;    //反过来不行，因为x的儿子变成y后那个因为“更换”而返给y儿子的节点被覆盖了，也就是说第三步没有任何意义了
}

void Splay(int x,int goal){//节点旋转到目标位置--zig-zag
    while (t[x].ff!=goal){
        int y=t[x].ff;
        int z=t[y].ff;
        if (z!=goal)
            (t[z].ch[0]==y)^(t[y].ch[0]==x)?rotate(x):rotate(y);
        rotate(x);
    }
    if (goal==0) root = x;
}

void insert(int x){// 1.find 2.splay
    int u=root,ff=0;
    while (u && t[u].val!=x){
        ff=u;
        u=t[u].ch[x>t[u].val];
    }
    u=tot++;
    t[ff].ch[x>t[ff].val]=u;
    t[u].val=x; t[u].ff=ff;
    t[u].ch[0]=t[u].ch[1]=0;
}

void Find(int x){
    int u=root,ff=0;
    /*
        搜索到第一个空节点。
       那么比另一个是第一个反过来拐的节点
       咋实现呢？
    */
   int l=0,r=0;
    while (u && t[u].val!=x){
        if (x>t[u].val) l=u,u=t[u].ch[0];
            else r=u,u=t[u].ch[1];
    }
    if (!u){
        if (x-t[l].val>t[r].val-x) u=r;
            else u=l;
    }
    Splay(u,0);
}

int Next(int x,int f){
    Find(x);
    int u=root;
    if ((t[u].val>x&&f)||(t[u].val<x&&!f)) return u;
    u=t[u].ch[f];
    while (t[u].ch[f^1]) u=t[u].ch[f^1];
    return u;
}
void Delete(int x){
    int last=Next(x,0);
    int next=Next(x,1);
    ans+=abs(t[root].val-x);
    ans%=mod;
    Splay(last,0); Splay(next,last);
    t[next].ch[0]=0;
    tot--;
}
int main(){
    int n;
    cin>>n;
    int treemode;
    while (n--){
        int mode,v;
        cin>>mode>>v;
        if (tot==0) insert(v),treemode=mode;
        else{
            if (treemode==mode) insert(v);
            else Delete(v);
        }
    }
    cout<<ans<<endl;
}