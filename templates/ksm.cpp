#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;

int ksm(int a,int n){
    int ret = 1;
    while (n){
        if (n&1) ret*=a;
        a*=a;
        a%=mod; ret%=mod;
        n=n>>1;
    }
    return ret;
}
const int INV2 = 500000004;
signed main(){
    int dp[6][1005][3];
    for (int i=1;i<=5;i++){
        for (int j=1;j<=5;j++){
            for (int k=0;k<3;k++){
                
            }
        }
    }
    cout<<ans<<endl;
}