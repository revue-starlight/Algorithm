#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;
const int N = 2e5+10;
const int mod = 1e9+7;
int dp1[N],dp2[N];
int n,k;
int fpow (int a, int b) { int ret = 1; while (b) { if (b & 1) ret = 1ll * ret * a % mod; a = 1ll * a * a % mod; b >>= 1; } return ret; }
void solve(){
    cin>>n>>k;
    dp1[0]=0; dp2[0]=1;
    for (int i=1;i<=k;i++){
        // all 
        if (n%2==0){
            dp1[i]=fpow((fpow(2,i-1)%mod),n);
        } else {
            dp1[i]=dp1[i-1]+dp2[i-1];
            dp1[i]%=mod;
        }
        // else
        if (n%2==1)
            dp2[i]=((fpow(2,n-1)%mod)*((dp2[i-1]+dp1[i-1])%mod))%mod;
        else 
            dp2[i]=(((fpow(2,n-1)+mod-1)%mod)*((dp2[i-1]+dp1[i-1])%mod))%mod;
    }
    int ans = (dp1[k]+dp2[k])%mod;
    cout<<ans<<endl;
}
signed main(){
    cin>>T;
    while (T--) solve();
}