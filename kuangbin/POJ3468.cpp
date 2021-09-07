#include <iostream>
using namespace std;
const int N = 2e5+100;
#define ll long long
#define int long long
int n;
int a[N];
ll tree[N<<2],lz[N<<2];
char s[100];
void build(int x,int l,int r){
    lz[x]=0;
    if (l==r){
        tree[x]=a[l]*1ll;
        return;
    }
    int mid = (l+r)>>1;
    build(x<<1,l,mid); build(x<<1|1,mid+1,r);
    tree[x]=tree[x<<1]+tree[x<<1|1];
}

void pushback(int x,int l,int r){
    if (lz[x]==0) return;
    int mid = (l+r)/2;
    tree[x<<1]+=lz[x]*(mid-l+1);
    tree[x<<1|1]+=lz[x]*(r-mid);
    lz[x<<1]+=lz[x];
    lz[x<<1|1]+=lz[x];
    lz[x]=0;
}

void update(int x,int l,int r,int L,int R,int val){
    pushback(x,l,r);
    if (L<=l && r<=R){
        tree[x]+=val*(r-l+1);
        lz[x]+=val;
        return;
    }
    int mid = (l+r)>>1;
    if (L<=mid) update(x<<1,l,mid,L,R,val);
    if (R>mid)  update(x<<1|1,mid+1,r,L,R,val);
    tree[x]=tree[x<<1]+tree[x<<1|1];
}

ll query(int x,int l,int r,int L,int R){
    pushback(x,l,r);
    if (L<=l && r<=R){
        return tree[x];
    }
    int mid = (l+r)>>1;
    int sum = 0;
    if (L<=mid) sum+=query(x<<1,l,mid,L,R);
    if (R>mid)  sum+=query(x<<1|1,mid+1,r,L,R);
    return sum;
}
int m;
void solve(){
    while (scanf("%lld%lld",&n,&m)!=EOF){
        for (int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        build(1,1,n);
        while (m--){
            int x,l,r;
            scanf("%s",s);
            if (s[0]=='C'){
                scanf("%lld%lld%lld",&l,&r,&x);
                update(1,1,n,l,r,x);
            }
            if (s[0]=='Q'){
                scanf("%lld%lld",&l,&r);
                printf("%lld\n",query(1,1,n,l,r));
            }
        }
    }
}
signed main(){
    int T;
    solve();
}