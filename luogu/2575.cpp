#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e2+10;
int T;
int sg[N][N];
int dfs(int n,int m){
    if (sg[n][m]!=-1) return sg[n][m];
    if (n==1 && m==1) return sg[n][m] = 0;
    int vis[2*N];
    memset(vis,0,sizeof(vis));
    for (int x = 2; x < n-1; x++){
        vis[dfs(x,m)^dfs(n-x,m)] = 1;
    }
    for (int y = 2; y < m-1; y++){
        vis[dfs(n,y)^dfs(n,m-y)] = 1;
    }
    for (int i=0;i<2*N;i++){
        if (!vis[i]) return sg[n][m] = i;
    }
    return 0;
}
void solve(){
    memset(sg,-1,sizeof(sg));
    int n,m;
    while (cin>>n>>m){
        if (dfs(n,m)) cout<<"WIN\n";
        else cout<<"LOSE\n";
    }
}
signed main(){
    //1ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //cin>>T;
    T = 1;
    while(T--)solve();
}