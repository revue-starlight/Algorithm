#include <bits/stdc++.h>
using namespace std;
const int N = 4e5+100;
int n;
int a[20][N];
int minn[N];
int endd[N];
int numm[N];
int dp[1<<21];
void trans(string s,int pos){
    for (int i=0;i<s.length();i++){
        if (s[i]=='(') a[pos][i]++; else a[pos][i]--;
        a[pos][i]+=a[pos][i];
        if (a[pos][i]<minn[i]){
            minn[i]=a[pos][i];
            numm[i]=0;
        }
        if (a[pos][i]==minn[i]) numm[i]++;
    }
}
void solve(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        string s;
        cin>>s;
        trans(s,i);
    }

    for (int i=0;i<(1<<n);i++){
        for (int j=0;j<n;j++){
            if ((i>>j)&1){//取第j个数字
                int from =  i - (1<<j);
                if (endd[from]<minn[i]){
                    dp[i]=max(dp[i],dp[from]);
                }
                if (endd[from]==minn[i]){
                    dp[i]=max(dp[i],dp[from]+numm[j+1]);
                }
            }
        }
    }
    cout<<dp[(1<<n)-1]<<"\n";
}
int main(){
    int T;
    //cin>>T;
    T = 1;
    memset(dp,-1,sizeof(dp)); 
    while (T--) solve();
}