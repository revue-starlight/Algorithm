#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
const int N = 5e2+10;
int dp[N][N];
int C[N][N],p[N][N];
const int mod = 998244353;
void init(){
  C[0][0] = 1;
  for (int i=1;i<N;i++){
    C[i][0]=1;
    for (int j=1;j<N;j++){
      C[i][j] = C[i-1][j]+C[i-1][j-1];
      C[i][j] = C[i][j]%mod; 
    }
  }
  for (int i=1;i<N;i++){
    p[i][0] = 1;
    for (int j=1;j<N;j++){
      p[i][j]=p[i][j-1]*i;
      p[i][j]%=mod;
    }
  }
}
void solve(){
  int n,x;
  cin>>n>>x;
  memset(dp,0,sizeof(dp));
  for (int i=1;i<=x;i++) dp[1][i] = i,dp[2][i] = i * (i - 1);
  for (int i=3;i<=n;i++){
    for (int j=i;j<=x;j++){
      for (int k=0;k<=i-1;k++){
        dp[i][j]+=((dp[i-k][j-i+1]*p[i-1][k])%mod*C[i][k])%mod;
        dp[i][j]%=mod;
      }
    }
  }
  int tot = p[x][n];
  tot = (tot + mod - dp[n][x])% mod;
  cout<<tot<<endl;
}
signed main(){
  init();
  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  //cin>>T;
  T = 1;
  while(T--)solve();
}