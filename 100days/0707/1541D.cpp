#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e2+100;
const int mod = 1e9+7;
struct Edge{
    int u,v,next;
}e[N];
int head[N],tot;
int n;
int f[N][20],dep[N],son[N];
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
        if (fa!=e[i].v) makelca(i,u,depth+1);
        son[u]+=son[e[i].v];
    }
    
}


int work(int u,int v){
    int ret = 0;
    int lca = -1;
    {// getlca
        if (dep[u]<dep[v]) swap(u,v);
        for (int i=20;i>=0;i--){
            if (dep[f[u][i]]>=dep[v]){
                u=f[u][i];
            }
        }
        if (u==v) lca = u;
        else {
            int tmpu,tmpv;
            tmpu=u;tmpv=v;
            for (int i=20;i>=0;i--){
                if (f[tmpu][i]!=f[tmpv][i]) tmpu = f[tmpu][i],tmpv = f[tmpv][i];
            }
            lca = f[tmpu][0];
        }
    }
    int ans = 0;
    int tmpu = u,tmpv = v;
    int dis = dep[u]+dep[v]-2*dep[lca];
    int cnt = 0;
    int pre = 0;
    while (tmpu!=lca){
        ans += dp[cnt][dis-cnt] * (son[tmpu]-son[pre]);
        ans %= mod;
        pre = tmpu;
        tmpu = f[tmpu][0];
        cnt++;
    }
    cnt = 0;
    int prev = 0;
    while (tmpv!=lca){
        ans += dp[dis-cnt][cnt]*(son[tmpv]-son[prev]);
        ans %= mod;
        prev = tmpv;
        tmpv = f[tmpv][0];
        cnt++;
    }
    
    ans += dp[dep[lca]-dep[u]][dep[lca]-dep[v]]*(son[lca]-son[prev]-son[pre]+(son[f[lca][0]]-son[lca]));
    ans %= mod;
    return ans;
}   

int m;
int main(){
    cin>>n>>m;
    for (int i=1;i<=m;i++){
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
    ret *= ksm(n,mod-2);
    return 0;
}