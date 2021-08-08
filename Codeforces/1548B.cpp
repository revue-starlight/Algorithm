#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N =  2e5+1;
ll a[N],b[N],t[N],LL[N],RR[N];
int cnt = 0;
void build(int x,int l,int r){
    LL[x]= l;RR[x] = r;
    if (l==r) {
        t[x]=b[l]; return;
    }
    int mid = (l+r)/2;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    t[x]=__gcd(t[x<<1],t[x<<1|1]);
}
int n;
int query(int x,int l){
    ll now = a[l];
    while (1){
        while (x&1){
            x/=2;
        }
        if (__gcd(now,t[x<<1|1])==1){
            x=x*2+1;
            if (__gcd(now,t[x<<1])==1) x = x*2;
            else now = __gcd(now,t[x<<1]),x = x*2+1;
            if (LL[x]==RR[x])
                return LL[x];
        } else {
            now = __gcd(now,t[x<<1|1]);
            x /=2;
        }
    }
}
void solve(){
    cnt++;
    scanf("%lld",&n);
    for (int i=1;i<=n;i++){
        scanf("%lld",a+i);
    }
    if (n==1) {
        printf("1\n");
        return;
    }
    for (int i=1;i<n;i++){
        b[i]=abs(a[i+1]-a[i]);
    }
    b[n]=1;
    build(1,1,n);
    return;
}
int main(){
    int T;
    scanf("%d",&T);
    while (T--) solve();
}