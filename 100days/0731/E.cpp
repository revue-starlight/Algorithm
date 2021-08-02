#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e6+10;
const int N = 3e5+10;
struct SEG{
    int val[M<<2],tag[M<<2],get[M<<2];
    void pushdown(int x,int l,int r){
        int mid = (l+r)>>1;
        val[x<<1]+=tag[x]*(mid+1-l);
        val[x<<1|1]+=tag[x]*(r-mid);
        tag[x<<1]+=tag[x];
        tag[x<<1|1]+=tag[x];
        tag[x]=0;
    }
    void update(int x,int l,int r,int L,int R,int v){
        pushdown(x,l,r);
        if (L<=l && r<=R){
            val[x]+=v*(r-l+1);
            get[x]=val[x]>0;
            return;
        }
        int mid = (l+r)/2;
        if (L<=mid) update(x<<1,l,mid,L,R,v);
        if (mid<R) update(x<<1|1,mid+1,r,L,R,v);
        val[x]=val[x<<1]+val[x<<1|1];
        get[x]=get[x<<1]&get[x<<1|1];
    }
}t;
struct QUERY{
    int l,r,w;
    const bool operator < (const  QUERY &rhs) const{
        return w<rhs.w;
    }
}q[N];
signed main(){
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>q[i].l>>q[i].r>>q[i].w;
    }
    sort(q+1,q+1+n);
    int l=1,r=0;
    int minn = numeric_limits<int>::max();
    while (l<=n){
        if (r<n && t.get[1]!=1) {
            ++r;
            t.update(1,1,m,q[r].l,q[r].r,1);
            continue;
        }
        if (t.get[1]==1){
            minn = min(q[r].w-q[l].w,minn);
            t.update(1,1,m,q[l].l,q[l].r,-1);
            ++l;
            continue;
        }
        break;
    }
    cout<<minn<<endl;
    return 0;
}