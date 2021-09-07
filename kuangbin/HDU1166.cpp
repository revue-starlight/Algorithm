#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e5+100;
#define ll long long
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

void pushback(int x){
    if (lz[x]==0) return;
    tree[x<<1]+=lz[x];
    tree[x<<1|1]+=lz[x];
    lz[x<<1]+=lz[x];
    lz[x<<1|1]+=lz[x];
    lz[x]=0;
}

void update(int x,int l,int r,int L,int R,int val){
    pushback(x);
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
    if (L<=l && r<=R){
        return tree[x];
    }
    int mid = (l+r)>>1;
    int sum = 0;
    if (L<=mid) sum+=query(x<<1,l,mid,L,R);
    if (R>mid)  sum+=query(x<<1|1,mid+1,r,L,R);
    return sum;
}
int Kase = 0;
void solve(){
    Kase++;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    build(1,1,n);
    printf("Case %d:\n",Kase);
    while (1){
        int x,l,r;
        scanf("%s",s);
        if (s[0]=='A' || s[0]=='S'){
            scanf("%d%d",&l,&x);
            if (s[0]=='S') x = -x;
            update(1,1,n,l,l,x);
        }
        if (s[0]=='Q'){
            scanf("%d%d",&l,&r);
            printf("%lld\n",query(1,1,n,l,r));
        }
        if (s[0]=='E'){
            break;
        }
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while (T--) solve();
}