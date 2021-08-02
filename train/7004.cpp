#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int fpow (int a, int b) { int ret = 1; while (b) { if (b & 1) ret = 1ll * ret * a % mod; a = 1ll * a * a % mod; b >>= 1; } return ret; }
int T;
void solve(){
    int l,r,k;
    cin>>l>>r>>k;
    if (k%2==0){
        int p = k/2;
        int ansa = (fpow(2,p)*l)%mod;
        int ansb = (fpow(2,p)*r)%mod;
        cout<<ansa<<" "<<ansb<<"\n";
    } else {
        int p = k/2;
        int ansa = (fpow(2,p)*l)%mod;
        int ansb = (fpow(2,p)*r)%mod;
        int aa ,bb;
        aa = (ansa+ansb)%mod; bb = (ansa-ansb+mod)%mod;
        cout<<aa<<" "<<bb<<"\n";
    }
}
signed main(){
    cin>>T;
    while (T--) solve();
}