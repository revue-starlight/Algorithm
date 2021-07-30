#include <bits/stdc++.h>
using namespace std;
const int N = 4e5+10;
int tree[N<<3];
int n;
int a[N];
void build(int x,int l,int r){
    if (l==r){
        tree[x]=a[l];
        return;
    }
    int mid = (l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r
    tree[x]=__gcd(tree[x<<1],tree[x<<1|1]);
}

int query(int x,int l,int r,int L,int R){
    if (L<=l && r<=R) return tree[x];
    int mid = (l+r)>>1;
    int ret = 0;
    if (L<=mid)
        ret = query(x<<1,l,mid,L,R);
    if (mid<R){
        if (ret==0) ret = query(x<<1|1,mid+1,r,L,R);
        else {
            ret = __gcd(ret,query(x<<1|1,mid+1,r,L,R));
        }
    }
    return ret;
}

int check(int mid){
    int ret = query(1,1,2*n,1,mid);
    for (int l=2;l<=n;l++){
        int r = l+mid-1;
        int ret2 = query(1,1,2*n,l,r);
        if (ret2 != ret){
            return 0;
        }
        ret = ret2;
    }
    return 1;
}
void solve(){
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=n;i++){
        a[i+n]=a[i];
    }
    build(1,1,2*n);
    int l = 1,r = n;
    while (l<r){
        int mid = (l+r)/2;
        if (check(mid)) r=mid; else l=mid+1;
    }
    cout<<l-1<<endl;
}
int main(){
    int T;
    cin>>T;
    while (T--) solve();
}