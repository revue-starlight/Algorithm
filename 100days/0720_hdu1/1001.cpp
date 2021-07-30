#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int T;
    cin>>T;
    while (T--){
        int n;
        cin>>n;
        n--;
        if (n==0 || n==1) cout<<0<<endl;
        if (n==2 || n==3) cout<<1<<endl;
        if (n<4) continue;
        int nn=n;
        int ans = 0;
        while (n){
            ans++;
            n/=2;
        }
        ans = 1ll*pow(2,ans-1)-1;
        cout<<ans<<endl;
    }
    // int n=100;
    // for (int i=1;i<=n;i++){
    //     int ans = 0;
    //     for (int j=1;j<=i;j++)
    //     {
    //         ans = ans | (i%j);
    //     }
    //     cout<<i<<":"<<ans<<endl;
    // }
}