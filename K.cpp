#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 4e5+30;
struct E{
    int u,v,p;
    const bool operator < (const E &rhs) const {
        return p<rhs.p;
    }
}e[N];
struct Qq{
    int id,val;
    const bool operator <( const Qq &rhs) const{
        return val>rhs.val;
    }
}qs[N];
int f[N];
int has[N];
int merged;
long long anss = 0;

int getf(int x){if (f[x]==x) return x; else return f[x]=getf(f[x]);}
void uni(int u,int v){
    int a = getf(u);
    int b = getf(v);
    if (a!=b){
        merged++;
        f[b]=a;
        anss += (has[a]*has[b]);
        has[a]+=has[b];
    }
}

int ans[N];
int T;
void solve(){
    merged=0;
    anss=0;
    int n,m,Q;
    cin>>n>>m>>Q;
    for (int i=1;i<=n;i++) f[i]=i;
    for (int i=1;i<=n;i++) has[i]=1;
    int x,y,k;
    for (int i=1;i<=n;i++){
       cin>>e[i].u>>e[i].v>>e[i].p; 
    }
    sort(e+1,e+1+m);
    int cnt = 0;
    int tmp = Q;
    while (tmp--){
        cnt ++;
        cin>>qs[cnt].val;
        qs[cnt].id = cnt;
    }
    sort(qs+1,qs+1+Q);
    int j = n;
    for (int i=1;i<=Q;i++){
        while (e[j].p>=qs[i].val){
            uni(e[j].u,e[j].v);
            j--;
        }
        ans[qs[i].id]=anss;
    }
    for (int i=1;i<=Q;i++) cout<<ans[i]<<"\n";
    return;
}
signed main(){
    cin>>T;
    while (T--){
        solve();
    }
}