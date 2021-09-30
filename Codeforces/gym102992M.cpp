#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const int N = 2e3+10;
struct E{
    int u,v,next;
}e[N<<3];
int T,n,tot;
int head[N],hp[N],siz[N];
int dp[N][N][2];
void add(int u,int v){e[++tot]={u,v,head[u]}; head[u]=tot;}
void dfs(int u,int fa){
    siz[u]+=1;
    dp[u][1][1]=hp[u]; 
    dp[u][0][0]=0; 
    for (int i=head[u];i;i=e[i].next){
        int v = e[i].v;
        if (v!=fa){
            dfs(v,u);
            for (int j=siz[u]+siz[v];j>=1;j--){
                for (int k=max(1ll,j-siz[u]);k<j && k<=siz[v];k++){
                    dp[u][j-1][0] = min(dp[u][j-1][0],dp[u][j-1-k][0]+dp[v][k][1]);
                    dp[u][j-1][0] = min(dp[u][j-1][0],dp[u][j-1-k][0]+dp[v][k][0]);
                    dp[u][j][1] = min(dp[u][j][1],dp[u][j-k][1]+dp[v][k][0]);
                    dp[u][j][1] = min(dp[u][j][1],dp[u][j-k][1]+dp[v][k][1]+hp[v]);
                }
            }
        //     for (int i = siz[u] + siz[v]; i >= 0; --i)
        //     {
        //     for (int j = max(0ll, i - siz[u]); j <= siz[v] && j <= i; ++j)
        //     {
        //         dp[u][i][0] = min(dp[u][i][0], dp[u][i - j][0] + dp[v][j][0]);
        //         if (j)
        //             dp[u][i][0] = min(dp[u][i][0], dp[u][i - j][0] + dp[v][j][1]);
        //     }
        //     }
        // for (int i = siz[u] + siz[v]; i >= 0; --i)
        // {
        //     for (int j = max(0ll, i - siz[u]); j <= siz[v] && j < i; ++j)
        //     {
        //         dp[u][i][1] = min(dp[u][i][1], dp[u][i - j][1] + dp[v][j][0]);
        //         if (j)
        //             dp[u][i][1] = min(dp[u][i][1], dp[u][i - j][1] + dp[v][j][1] + hp[v]);
        //     }
        // }
            siz[u]+=siz[v];
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while (T--){
        cin>>n;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++) dp[j][i][0]=dp[j][i][1]=0x3f3f3f3f3f3f3f3f;
        for (int i=1;i<=n;i++) siz[i]=0;
        for (int i=1;i<=n;i++) head[i]=0; tot = 0;
        for (int i=2;i<=n;i++){
            int p; cin>>p;
            add(i,p); add(p,i);
        }
        for (int i=1;i<=n;i++) cin>>hp[i],tot+=hp[i];
        dfs(1,0);
        tot=tot*2-hp[1];
        for (int i=n;i>=0;i--){
            cout<<min(dp[1][i][1],dp[1][i][0])<<" ";
        }
        cout<<"\n";
    }
    //cout<<cnt;
}