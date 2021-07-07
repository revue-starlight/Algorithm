#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 400;
const int mod = 1e9+7;
struct Edge{
    int u,v,next;
}e[N<<2];
int head[N],tot;
int n;
int f[N][21],dep[N],son[N];
int dp[N][N];
void add(int u,int v){e[++tot]={u,v,head[u]}; head[u]=tot;}

int ksm(int a,int n){
    int ret = 1;
    while (n){
        if (n&1) ret*=a;
        a*=a;
        a%=mod; ret%=mod;
        n=n>>1;
    }
    return ret;
}
void makelca(int u,int fa,int depth){
    f[u][0]=fa;
    dep[u]=depth;
    son[u]=1;
    for (int i=1;i<=20;i++){
        f[u][i]=f[f[u][i-1]][i-1];
    }
    for (int i=head[u];i;i=e[i].next){
        if (fa!=e[i].v) {
            makelca(e[i].v,u,depth+1);
            son[u]+=son[e[i].v];
        }
    }
    
}


int work(int u,int v){
    int ret = 0;
    int lca = -1;
    int uu=u,vv=v;
    {// getlca
        bool flag =1;
        if (dep[u]<dep[v]) swap(u,v);
        int tmpu = u;
        for (int i=20;i>=0;i--){
            if (dep[f[u][i]]>=dep[v]){
                u=f[u][i];
            }
        }
        if (u==v) {lca = u;}
        else {
            int tmpu,tmpv;
            tmpu=u;tmpv=v;
            for (int i=20;i>=0;i--){
                if (f[tmpu][i]!=f[tmpv][i]) tmpu = f[tmpu][i],tmpv = f[tmpv][i];
            }
            lca = f[tmpu][0];
        }
    }
    u=uu,v=vv;
    int ans = 0;
    int tmpu = u,tmpv = v;
    int dis = dep[u]+dep[v]-2*dep[lca];
    int cnt = 0;
    int pre = 0;
    while (tmpu!=lca){
        ans = ans + (dp[cnt][dis-cnt] * (son[tmpu]-son[pre])) % mod;
        ans %= mod;
        pre = tmpu;
        tmpu = f[tmpu][0];
        cnt++;
    }
    cnt = 0;
    int prev = 0;
    while (tmpv!=lca){
        ans = ans + (dp[dis-cnt][cnt]*(son[tmpv]-son[prev])) % mod;
        ans %= mod;
        prev = tmpv;
        tmpv = f[tmpv][0];
        cnt++;
    }
    
    ans = ans + (dp[dep[u]-dep[lca]][dep[v]-dep[lca]]*(son[lca]-son[prev]-son[pre]+(n-son[lca]))) % mod;
    ans %= mod;
    ans = (ans * ksm(n,mod-2)) % mod;
    return ans;
}   

int m;
signed main(){
    freopen("a.in","r",stdin);
    for (int i=0;i<N;i++)
        for (int j=0;j<N;j++){
            if (i==0) dp[i][j]=0;
            else if (j==0) dp[i][j]=1;
            else
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod*ksm(2,mod-2)%mod;
    }

    cin>>n;
    for (int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        add(x,y); add(y,x);
    }
    makelca(1,1,1);
    int ret = 0;
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            if (i!=j){
                ret += work(i,j);
                ret %= mod;
            }
        }
    }
    cout<<ret<<endl;
    return 0;
}