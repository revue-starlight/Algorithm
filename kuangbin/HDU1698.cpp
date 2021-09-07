#include <iostream>
using namespace std;
#define int long long
int T;
const int N = 1e5+100;
int t[N<<2];
int lz[N<<2];
void pushdown(int x,int l,int r){
    if (l==r) return;
    if (lz[x]==0) return;
    int mid = (l+r)>>1;
    t[x<<1]=lz[x]*(mid-l+1);
    t[x<<1|1]=lz[x]*(r-mid);
    lz[x<<1]=lz[x<<1|1]=lz[x];
    lz[x]=0;
}

void update(int x,int l,int r,int L,int R,int val){
    if (L<=l && r<=R) {
        t[x]=val*(r-l+1);
        lz[x]=val;
        return;
    }
    int mid = (l+r)/2;
    pushdown(x,l,r);
    if (L<=mid) update(x<<1,l,mid,L,R,val);
    if (R>mid) update(x<<1|1,mid+1,r,L,R,val);
    t[x]=t[x<<1]+t[x<<1|1];
}

int cnt = 0;
void solve(){
    int n,q;
    cnt++;
    cin>>n>>q;
    update(1,1,n,1,n,1);
    for (int i=1;i<=q;i++){
        int a,b,z;
        scanf("%lld%lld%lld",&a,&b,&z);
        update(1,1,n,a,b,z);
    }
    printf("Case %d: The total value of the hook is %lld.\n",cnt,t[1]);
}
signed main(){

    int T;
    scanf("%lld",&T);
    while (T--) solve();
}