#include <bits/stdc++.h>
using namespace std;
const int N = 2005,M = 2005;
int m,n,k;
double p1,p2,p3,p4;
double dp[N][M];
int main(){
    while (cin>>n){
        cin>>m>>k>>p1>>p2>>p3>>p4;
        for (int i=1;i<=n;i++){
            for (int j=i;j>=1;j--){
                if (j==1){
                    dp[i][j]=(p2*dp[i][i]+p4)/(1-p1);
                } else {
                    dp[i][j]=(p2*dp[i][j-1]+p3*dp[i-1][j-1]+p4)/(1-p1);
                }
            }
        }
        
    }
}