#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+100;
const int M = 5e5+100;
int fa[N];
struct Edge{
    int u,v,w,next;
    const bool operator < (const Edge &rhs) const{return w<rhs.w;}
}e[M];
int head[N],tot;
int n,m,k;
void add(int u,int v,int w){e[++tot]={u,v,w,head[u]}; head[u]=tot;}
int getfa(int x){return x == fa[x] ? x : fa[x] = getfa(fa[x]);}
int check(int x){
     int siz = n;
     for (int i=1;i<=n;i++) fa[i]=i;
     for (int i=1;i<=m;++i){
         if (e[i].w>x) break;
        if (getfa(e[i].u)!=getfa(e[i].v)) {--siz;fa[getfa(e[i].u)]=getfa(e[i].v);}
    // }
    // return K;
    //for (int i=1;i<=n;i++){fa[i]=i;}
    //int siz=n;
    //for (int i=1;i<=m;i++){
    //    if (e[i].w>x) break;
    //    int x = getfa(e[i].u);
    //    int y = getfa(e[i].v);
    //    if (x!=y)
    //        siz--,fa[x]=y;
    }
    return siz;
}

void solve(){
    tot = 0;
    scanf("%lld%lld%lld",&n,&m,&k);
    for (int i=1;i<=m;i++){
        int u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        add(u,v,w);
    }
    sort(e+1,e+1+m);
    int u,v,w;
    int l=0,r=1e9;
    while (l<r){
        int mid = (l+r)>>1;
        if (check(mid)<=k) r=mid; else l=mid+1;
    }
    if (check(l)==k) cout<<l<<"\n";
    else cout<<"-1\n";
}
signed main(){
    //freopen("/home/cyq/Documents/hdu2020/hdu1/KD_Graph/1.in","r",stdin);
    int T;
    scanf("%lld",&T);
    while (T--) solve();
}