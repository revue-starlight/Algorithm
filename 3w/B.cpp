#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int ans[101];
int qpow(int a, int n)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 1)
        return (qpow(a, n - 1) * a)%mod;
    else
    {
        int temp = qpow(a, n / 2)%mod;;
        return (temp * temp)%mod;
    }
}

signed main(){
    int T;
    cin>>T;
    memset(ans,-1,sizeof(ans));
    int fm = qpow(10000,mod-2);
    while (T--){
        int n;
        cin>>n;
        if (ans[n]!=-1) cout<<ans[n]<<"\n";
        else {
            ans[n]=fm*(10000-200*n+n*n);
            ans[n]%=mod;
            cout<<ans[n]<<"\n";
        }
    }
}