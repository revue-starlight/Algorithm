#include <bits/stdc++.h>
using namespace std;
const int N = 5e3+10;
int dp[N][N];
int a[N],n;
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        a[i]++;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++) dp[i][j]=dp[i-1][j];
        for (int j=a[i]-1;j>=1;j--) dp[i][j]++;
    }
    int ans = 0;
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            if (a[i]>a[j]) ans++;
        }
    }
    int cnt = 1;
    int minn = ans;
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            if (a[i]<a[j]) continue;
            int pre = dp[i][a[i]]+dp[j][a[j]];
            int now = (dp[i][a[j]]-1)+dp[j][a[i]];
            int midPos = (dp[j-1][a[j]]-dp[j-1][a[i]-1]) - (dp[i][a[j]] - dp[i][a[i]-1]);
            if (ans+now-pre-midPos<minn){
                cnt = 1;
                minn = ans+now-pre-midPos;
            } else if (ans+now-pre-midPos==minn) cnt++;
        }
    }
    cout<<minn<<" "<<cnt;
    return 0;
}