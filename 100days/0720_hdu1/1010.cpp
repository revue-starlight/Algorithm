#include <iostream>
#include <cmath>
#include <algorithm>
#include <unordered_set>
using namespace std;
#define int long long
int u,v,w;
const int N=1e5+10;
const int M =5e5+10;
int fa[N];
int getfa(int x){return x == fa[x] ? x : fa[x] = getfa(fa[x]);}
int n,m,k;
int siz = n;
struct E{
    int u,v,w;
    const bool operator < (const E &rhs)const{return w<rhs.w;}
}e[M];
int tot;
void add(int u,int v,int w){e[++tot]={u,v,w};}
int cntt=0;

int check(int x){
    for (int i=1;i<=n;i++){fa[i]=i;}
    int siz=n,i=0;
    for (i=1;i<=m;i++){
        const auto &ee = e[i];
        if (ee.w>x) break;
        int x = getfa(ee.u);
        int y = getfa(ee.v);
        if (x!=y)
            siz--,fa[x]=y;
    }
    return siz;
}
void solve(){
    tot=0;
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
    }
    sort(e+1,e+1+m);
    int l=0,r=1e9;
    int mid;
    while (l<r){
        cntt++;
        mid = (l+r)>>1;
        if (check(mid)<=k) r=mid; else l=mid+1;
    }
    if (check(l)==k){
        cout<<l<<"\n";
    }
    else cout<<"-1"<<"\n";
    //cout<<"checK;"<<cntt<<endl;
}
signed main(){
    //freopen("1.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin>>T;
    while (T--) solve();
}