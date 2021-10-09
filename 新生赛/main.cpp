#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int mod = 998244353;
int fpow(int a,int n){
    int ret = 1;
    while (n){
        if (n&1) ret*=a;
        a*=a;
        a%=mod; ret%=mod;
        n=n>>1;
    }
    return ret;
}
signed main(){
    cin>>n>>m;
    int ans = fpow(2,n)+fpow(2,m);
    ans%=mod;
    ans+=(mod-2);
    ans%=mod;
    cout<<ans<<"\n";
}