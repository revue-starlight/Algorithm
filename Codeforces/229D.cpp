#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int pre[N],a[N];
int n,dp[N],num[N];
int main(){   
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++){
        int ans = 0;
        for (int j=i;j>0;j--){
            ans+=a[j];
            if (ans>=dp[j-1]) {
                dp[i]=ans;
                num[i]=num[j-1]+1;
                break;
            }
        }
    }
    cout<<n-num[n]<<"\n";
    return 0;
}