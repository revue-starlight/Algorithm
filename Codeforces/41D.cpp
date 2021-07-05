#include <bits/stdc++.h>
using namespace std;
const int N = 105, K = 11;
int dp[N][N][K],a[N][N];
struct FA{
    int x,y,k;
}fa[N][N][K];
int n,m,k;
vector <FA> vec;
int main(){
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++){
        string s;
        cin>>s;
        for (int j=1;j<=m;j++){
            a[i][j]=s[j-1]-'0';
        }
    }
    memset(dp,-1,sizeof(dp));
    k=k+1;
    for (int i=1;i<=m;i++){
        dp[n][i][a[n][i]%k]=a[n][i];
    }
    for (int i=n;i>=1;i--){
        for (int j=1;j<=m;j++){
            for (int p=0;p<k;p++){
                if (dp[i+1][j-1][(p+10*k-a[i][j])%k]!=-1) {dp[i][j][p]=dp[i+1][j-1][(p+10*k-a[i][j])%k]+a[i][j]; fa[i][j][p]={i+1,j-1,(p+10*k-a[i][j])%k}; }
                if (dp[i+1][j+1][(p+10*k-a[i][j])%k]!=-1) { if (dp[i+1][j+1][(p+10*k-a[i][j])%k]+a[i][j]>dp[i][j][p]) fa[i][j][p]={i+1,j+1,(p+10*k-a[i][j])%k}; dp[i][j][p]=max(dp[i][j][p],dp[i+1][j+1][(p+10*k-a[i][j])%k]+a[i][j]);}
            }
        }
    }
    int ind = -1,maxx=-1;
    for (int i=1;i<=m;i++){
        if (maxx<dp[1][i][0]) {
            maxx = dp[1][i][0];
            ind = i;
        }
    }
    if (ind == -1) {
        cout<<"-1";
    } else{
        cout<<maxx<<"\n";
        vec.push_back({1,ind,0});
        int len=0;
        while (1){
            if (vec[len].x==n) break;
            FA temp = fa[vec[len].x][vec[len].y][vec[len].k];
            vec.push_back({temp.x,temp.y,temp.k});
            len++;
        }
        cout<<vec[len].y<<"\n";
        for (int i=len-1;i>=0;i--){
            if (vec[i].y-vec[i+1].y==1) cout<<"R"; else cout<<"L";
        }
    }
    return 0;
}