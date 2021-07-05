#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define ll long long
const int N = 5e3+10;
struct Edge{
    int u,v,next;
}e[N*2];
const int mod = 998244353;
int head[N],tot;
void add(int u,int v){
    e[++tot]={u,v,head[u]}; head[u]=tot;
}
int n,k;
int dep[N],maxdep[N];
int dp[N][N];
int tmp[N];
int siz[N];
void dfs(int u,int fa){
    siz[u]=1;maxdep[u]=dep[u];
	dp[u][0]=1;
	for (int ii=head[u];ii;ii=e[ii].next)
	{
        int v=e[ii].v;
		if(v==fa)continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
		int kk=maxdep[u]-dep[u];
		FOR(i,0,max(maxdep[u],maxdep[v])-dep[u])tmp[i]=0;
		FOR(i,0,kk)
		{
			FOR(j,0,maxdep[v]-dep[u])
			{
				tmp[i]=(tmp[i]+1ll*dp[u][i]*dp[v][j]%mod)%mod;
				if(i+j+1>k)continue;
				tmp[max(i,j+1)]=(tmp[max(i,j+1)]+1ll*dp[u][i]*dp[v][j]%mod)%mod;
			}
		}
		maxdep[u]=max(maxdep[u],maxdep[v]);
		FOR(i,0,maxdep[u]-dep[u])dp[u][i]=tmp[i];
		siz[u]+=siz[v];
	}
}
int ans=0;
void solve(){
    dfs(1,0);
    for (int i=0;i<=k;i++) ans=(ans+dp[1][i])%mod;
    cout<<ans;
}
signed main(){
	
	cin>>n>>k;
    for (int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    solve();
}