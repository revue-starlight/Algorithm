#include <bits/stdc++.h>
using namespace std;
const int N =1e5+10;
vector <int> pdiv[N];
int a[N],dp[18][N],nex[N];
int main(){
    int m,n;
    cin>>n>>m;
    for (int i=2;i=N;i++){
        if (pdiv[i].empty()){
            nex[i]=n+1;
            for (int j=i;j<N;j+=i) pdiv[j].push_back(i);
        }
    }
    for (int i=1;i<=n;i++)  cin>>a[i];
    dp[0][n+1]=n+1;
    for (int i=n;i>=1;i--){
        dp[0][i]=dp[0][i+1];
        for (auto p:pdiv[a[i]]){
            dp[0][i]=min(dp[0][i],nex[p]);
            nex[p]=i;
        }
    }
    for (int i=1;i<18;i++){
        for (int j=n+1;j>=1;j--)
            dp[i][j]=dp[i-1][dp[i-1][j]];
    }
 
    while (m--){
        int l,r;
        cin>>l>>r;
        int now=l;
        int ans=0;
        int i=0;
        while (dp[i][now]<=r){
            if (dp[i+1][now]>r){
                now=dp[i+1][now];
                ans+=pow(2,i);
                i=0;
            }
            else i++;
        }
        ans+=1;
        cout<<ans<<endl;
    }
    return 0;
    
}
