#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 301;
int vis[N];
int dis[N][N];
signed main(){
    int n,m,s,q;
    memset(vis,-1,sizeof(vis));

    scanf("%lld%lld%lld%lld",&n,&m,&s,&q);
        for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            dis[i][j]=1e18;
    for (int i=1;i<=m;i++){
        int u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);     
        if (u!=v && w<dis[u][v]){
            dis[u][v]=w;
        }
    }
    for (int i=1;i<=n;i++) dis[i][i]=0;
    vis[s]=1;
    while (q--){
        int type,k;
        scanf("%lld%lld",&type,&k);
        if (type == 1){
            if (vis[k]!=1){
                vis[k]=1;
                for (int i=1;i<=n;i++){
                    for (int j=1;j<=n;j++){
                        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                    }
                }
            }
        } else if (type == 2){
            if (!vis[k] || dis[s][k]==1e18){
                printf("-1\n");
            } else {
                printf("%lld\n",dis[s][k]);
                s=k;
            }
        }
    }

}