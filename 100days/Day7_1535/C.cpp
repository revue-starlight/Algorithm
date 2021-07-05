#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
int T;
const int N = 4e5;
int dp[N][2];
void solve(){
    string s;
    cin>>s;
    s='?'+s;
    for (int i=0;i<=s.length();i++) dp[i][0]=dp[i][1]=0;
		ll res=0;
		for(int i=1;i<s.size();i++)
		{
			if(s[i]=='1'||s[i]=='?')
				dp[i][1]=dp[i-1][0]+1;
			if(s[i]=='0'||s[i]=='?')
				dp[i][0]=dp[i-1][1]+1;
			res+=max(dp[i][0],dp[i][1]);
		}
		cout<<res<<'\n';
}
signed main(){
    cin>>T;
    while (T--) solve();
    return 0;
}