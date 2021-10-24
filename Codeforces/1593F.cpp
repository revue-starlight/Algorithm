#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
const int N = 45;
struct ORI{
    int val,k;
};
int a[N];
int dp[N][N][N][N];
ORI origin[N][N][N][N];
void solve(){
    int n,A,B;
    string s;
    cin>>n>>A>>B;
    cin>>s;
    int len = s.length();
    for (int i=0;i<n;i++){
        a[i+1]=s[i]-'0';
    }
    memset(dp,0,sizeof(dp));
    dp[0][0][0][0]=1;
    for (int i=0;i<n;i++){
        for (int r=0;r<=i;r++){
            for (int j=0;j<A;j++){
                for (int k=0;k<B;k++){
                    if (dp[i][r][j][k]==false) continue;
                    
                    dp[i+1][r+1][(j*10+a[i+1])%A][k] = 1;
                    origin[i+1][r+1][(j*10+a[i+1])%A][k] = {1,j};

                    dp[i+1][r][j][(k*10+a[i+1])%B] = 1;
                    origin[i+1][r][j][(k*10+a[i+1])%B] = {0,k};
                }
            }
        }
    }
    int ans = numeric_limits<int>::max();
    int r=0;
    for (int i=1;i<n;i++){
        if (dp[n][i][0][0] == 1){
            if (abs(n-2*r)>=abs(n-2*i))
                r = i;
        }
    }
    if (r == 0){
        cout<<"-1\n";
    } else {
        string ss = "";
        int j=0,k=0,i=n;
        for (i=n,j=0,k=0;i>=1;i--){
            ORI tmp = origin[i][r][j][k];
            if (tmp.val == 0){
                ss+='B';
                k = tmp.k;
            } else {
                ss+='R';
                r--;
                j = tmp.k;
            }
        }
        for (int i=ss.length()-1;i>=0;i--) cout<<ss[i];
        cout<<"\n";    
    }
}
signed main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--)solve();
}