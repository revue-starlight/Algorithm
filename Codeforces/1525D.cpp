#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
void solve(){
    int n;
    cin>>n;
    vector <int> full={0};
    vector <int> empty={0};
    for (int i=1;i<=n;i++){
        int x;
        cin>>x;
        if (x==1) full.push_back(i);
        else empty.push_back(i);
    }
    int dp[2][n+1]; memset(dp,0,sizeof(dp));
    dp[0][0]=0;
    int now;
    for (int i=1;i<full.size();i++){
        now = i%2;
        for (int j=0;j<empty.size();j++) dp[now][j]=0x3f3f3f3f3f3f3f3f;
        for (int j=i;j<empty.size();j++){
            dp[now][j]=min(dp[now^1][j-1]+abs(full[i]-empty[j]),dp[now][j-1]);
        }
    }
    if (full.size()==1){
        cout<<0<<"\n";
        return;
    }
    cout<<dp[now][empty.size()-1]<<"\n";
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //cin>>T;
    T=1;
    while(T--)solve();
}