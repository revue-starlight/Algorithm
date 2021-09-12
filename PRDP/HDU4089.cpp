#include <bits/stdc++.h>
using namespace std;
const int N = 2005,M = 2005;
int m,n,k;
double p1,p2,p3,p4;
double dp[N][M];
int main(){
    while (cin>>n){
        memset(dp,0,sizeof(dp));
        cin>>m>>k>>p1>>p2>>p3>>p4;
        for (int i=1;i<=n;i++){
            double A = p2*(1-p1), B = dp[i-1][i-1]*p3+p4;
            for (int j=i-1;j>=1;j--){
                if (j<=k)
                    B = B + (dp[i-1][j-1]*p3+p4)*A;
                else 
                    B = B + (dp[i-1][j-1]*p3)*A;
                A = A * p2*(1-p1);
            }

            B += p4*(1-p1)*A;
            A *= p2*(1-p1);
            dp[i][i]=B/(1-A);
            for (int j=1;j<=i;j++){
                if (j==1){
                    dp[i][j]=(p2*dp[i][i]+p4)/(1-p1);
                } else {
                    if (j<=k)
                    dp[i][j]=(p2*dp[i][j-1]+p3*dp[i-1][j-1]+p4)/(1-p1);
                    else 
                    dp[i][j]=(p2*dp[i][j-1]+p3*dp[i-1][j-1])/(1-p1);
                }
            }
        }
        cout<<dp[n][m]<<endl;
    }
}