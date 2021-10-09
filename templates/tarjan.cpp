#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5+10,M = 5e5+10;
int dfn[N],low[N],vis[N],dfs_num;
int stackk[N],top;
struct Edge{
    int u,v,next;
}e[N<<2];
int tot,head[N],color[N];
int col_num;
void add(int u,int v){e[++tot]={u,v,head[u]}; head[u]=tot;}
void Tarjan ( int x ) {
         dfn[ x ] = ++dfs_num ;
         low[ x ] = dfs_num ;
         vis [ x ] = true ;//是否在栈中
         stackk [ ++top ] = x ;
         for ( int i=head[ x ] ; i!=0 ; i=e[i].next ){
                  int temp = e[ i ].v ;
                  if ( !dfn[ temp ] ){
                           Tarjan ( temp ) ;
                           low[ x ] = min ( low[ x ] , low[ temp ] ) ;
                 }
                 else if ( vis[ temp ])low[ x ] = min ( low[ x ] , dfn[ temp ] ) ;
         }
         if ( dfn[ x ]==low[ x ] ) {//构成强连通分量
                  vis[ x ] = false ;
                  color[ x ] = ++col_num ;//染色
                  while ( stackk[ top ] != x ) {//清空
                           color [stackk[ top ]] = col_num ;
                           vis [ stackk[ top-- ] ] = false ;
                 }
                 top -- ;
         }
}
signed main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        int u,v;
        cin>>u>>v;
        add(u,v);
    }Tarjan(1);
    for (int i=1;i<=5;i++){
        cout<<color[i]<<' ';
    }
}