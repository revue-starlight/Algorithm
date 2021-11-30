#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3+100;
int T;
int n,p;
int head[N],tot;
struct Edge{
    int u,v,next;
}e[N<<2];
int ans = 0x3f3f3f3f3f3f3f3f;
int dp[N][N];
void add(int u,int v){e[++tot]={u,v,head[u]};head[u]=tot;}
int dfs(int u,int fa){
    dp[u][0] = 1;
    dp[u][1] = 0;
    int sum = 1;
    int newdp[N];
    for (int i=head[u];i;i=e[i].next){
        int v = e[i].v;
        if (v==fa) continue;
        int vsz = dfs(v,u);
        memset(newdp,0x3f,sizeof(newdp));
        for (int j=1;j<=sum;j++){
            for (int k=0;k<=vsz;k++){
                newdp[j+k]=min(newdp[j+k],dp[u][j]+dp[v][k]);
            }
        }
        sum+=vsz;
        for (int i=1;i<N;i++) dp[u][i] = newdp[i];
    }
    
    ans = min(ans,dp[u][p]+(u!=1));
    return sum;
}
void solve(){
    cin>>n>>p;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++) dp[i][j] = 0x3f3f3f3f3f3f3f3f;
    }
    for (int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        add(u,v); add(v,u);
    }
    dfs(1,1);
    cout<<ans<<"\n";
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //cin>>T;
    T = 1;
    while(T--)solve();
}