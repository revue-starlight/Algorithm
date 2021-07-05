#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=2e5+10;
const ll mod=1e9+7;
ll a[maxn],inv[maxn],sum[maxn];

ll fpow(ll a,ll x){
    ll res=1;
    while (x){
        if (x&1) res=res*a%mod;
        a=a*a%mod;
        x=x>>1;
    }
    res%=mod;
    return res;
}

void init(){
    inv[1]=1;
    for (ll i=2;i<maxn;i++) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    for (ll i=1;i<maxn;i++) inv[i]=inv[i]+inv[i-1],inv[i]%=mod;
}
void solve(){
    ll n;
    cin>>n;
    for (ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    for (ll i=1;i<=n;i++) sum[i]=sum[i-1]+a[i],sum[i]%=mod;
    ll ret=0,res=0;
    for (ll i=1;i<=n/2;i++){
        ret=(mod+inv[n-i+1]-inv[i-1]); ret%=mod;
        ret=ret*((mod+sum[n-i+1]-sum[i-1])%mod); ret%=mod;
        res=res+ret;
        res%=mod;
    }
    if (n&1) res+=(a[n/2+1]*fpow(n/2+1,mod-2));
    res%=mod;
    res=res*fpow((n*n+n)/2%mod,mod-2);
    res%=mod;
    printf("%lld\n",res);
}

int main(){
    init();
    int T;
    cin>>T;
    while (T--) solve();
}