#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;
int n,m,k;
struct SEG{
int val[N<<2],tag[N<<2];
void init(){
    update(1,1,m,1,m,0);
}
void pushdown(int x,int l,int r){
    int mid = (l+r)>>1;
    if (l==r) return;
    if (tag[x]==2){
        tag[x<<1]=tag[x<<1|1]=tag[x];
        tag[x]=0;
        val[x<<1]=(mid-l+1)*tag[x];
        val[x<<1|1]=(r-mid)*tag[x];
    }
    if (tag[x]==1){
        tag[x<<1]=tag[x<<1|1]=tag[x];
        val[x<<1]=(mid-l+1)*tag[x];
        val[x<<1|1]=(r-mid)*tag[x];
        tag[x]=0;
    }
    return;
}
int query(int x,int l,int r,int L,int R){//find the first node
    pushdown(x,l,r);
    if (l==r) {
        if (val[x]==1) return l;
        else return m+1;
    }

    int mid = (l+r)/2;
    if (L<=l && r<=R){
        if (val[x<<1]>0) return query(x<<1,l,mid,L,R);
        if (val[x<<1|1]>0) return query(x<<1|1,mid+1,r,L,R);
        return m+1;
    }
    int ret = m+1;
    if (L<=mid) ret = min(ret,query(x<<1,l,mid,L,R));
    if (R>mid) ret = min(ret,query(x<<1|1,mid+1,r,L,R));
    return ret;
}
void update(int x,int l,int r,int L,int R,int v){
    pushdown(x,l,r);
    if (L<=l && r<=R){
        val[x]=v*(r-l+1);
        int tmp;
        if (v==0) tmp = 2; else tmp = 1;
        tag[x]=tmp;
        return;
    }
    int mid = (l+r)/2;
    if (L<=mid) update(x<<1,l,mid,L,R,v);
    if (mid<R) update(x<<1|1,mid+1,r,L,R,v);
    val[x]=val[x<<1]+val[x<<1|1];
}
}s[2];
vector <int> vec[N];
void solve(){
    cin>>n>>m>>k;
    s[0].init();
    s[0].update(1,1,m,1,1,1);
    int x,y;
    for (int i=1;i<=n;i++) vec[i].clear();
    for (int i=1;i<=k;i++){
        int x,y;cin>>x>>y;
        vec[x].push_back(y);
    }
    int ans = 0;
    for (int i=1;i<=n;i++){
        s[(i&1)].init();
        sort(vec[i].begin(),vec[i].end());
        int l = 0;
        for (auto &y:vec[i]){
            if (y-1>=l+1){
                int ll = s[(i&1)^1].query(1,1,m,l+1,y-1);
                if (ll<=y-1){
                    s[(i&1)].update(1,1,m,ll,y-1,1);
                }
            }
            l = y;
        }
        if (l+1<=m){
            int ll = s[(i&1)^1].query(1,1,m,l+1,m);
            if (ll<=m){
                s[(i&1)].update(1,1,m,ll,m,1);
            }
        }
        ans+=s[(i&1)].val[1];
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while (T--){
        solve();
    }
}