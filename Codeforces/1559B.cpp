#include <bits/stdc++.h>
using namespace std;
const int N = 104;
int ans[105][2];
int pre[105][2];
int p[104];
int main(){
    int T;
    cin>>T;
    while (T--){
        int n;string s;
        cin>>n>>s;
        string ans[2]={"",""};
        int dp[2]={0,0};
        for (int i=0;i<n;i++){
            string s0,s1;
            int dp0,dp1;
            if (s[i]=='?'){
                if (dp[0]+1<dp[1]){
                    dp0=dp[0]+1;
                    s0=ans[0]+"B";
                } else {
                    dp0=dp[1];
                    s0=ans[1]+"B";
                }
                if (dp[1]+1<dp[0]){
                    dp1=dp[1]+1;
                    s1=ans[1]+"R";
                } else {
                    dp1=dp[0];
                    s1=ans[0]+"R";
                }
                ans[0]=s0; ans[1]=s1;
                dp[0]=dp0; dp[1]=dp1;
            } else {
                if (s[i]=='B'){//0
                    if (dp[0]+1<dp[1]){
                        dp[0]=dp[0]+1;
                        s0 = ans[0]+"B";
                    } else {
                        dp[0]=dp[1];
                        s0 = ans[1]+"B";
                    }
                    ans[0]=s0; ans[1]="";
                    dp[1]=999999;
                }
                if (s[i]=='R'){//1
                    if (dp[1]+1<dp[0]){
                        dp[1]=dp[1]+1;
                        s1 = ans[1]+"R";
                    } else {
                        dp[1]=dp[0];
                        s1 = ans[0]+"R";
                    }
                    ans[1]=s1; ans[0]="";
                    dp[0]=999999;
                }
            }
        }
        if (dp[0]<dp[1]){cout<<ans[0]<<"\n";} else cout<<ans[1]<<"\n";
    }
}