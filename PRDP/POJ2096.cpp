#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+100;
int n,s;
double dp[N][N];
int main(){
    while (scanf("%d%d",&n,&s)!=EOF){
        dp[0][0]=0;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=s;j++){
                double p1,p2,p3,p4;
                p1 = 1.0*(n-(i-1))/n;
                p2 = 1.0*(s-(j-1))/s;
                p3 = p1*p2;
                p4 = 1-p1-p2+p3;
                dp[i][j]=((dp[i-1][j-1]*p3)+dp[i-1][j]*(p1)+dp[i][j-1]*p2)/(1-p4)+1;
            }
        }
        printf("%.4lf\n",dp[n][s]);
    }
}