#include <bits/stdc++.h>
using namespace std;
int T;
const int N = 1e2+100;
struct Edge{
    int u,v,next;
}e[N<<2];
int tot,head[N];
int vis[N],siz[N]; 
void add(int u,int v){e[++tot]={u,v,head[u]}; head[u]=tot;}
void dfs(int u,int last){

}
void solve(){
    int n,k;    
    cin>>n>>k;
    for (int i=1;i<=n;i++) head[i]=0; tot = 0;
    int u,v;
    for (int i=1;i<=n;i++){
        cin>>u>>v;
        add(u,v); add(v,u);
    }
    dfs(1,0);
}
int main(){
    cin>>T;
    while (T--) solve();
}