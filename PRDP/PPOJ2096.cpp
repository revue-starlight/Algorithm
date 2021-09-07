#include<algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
#define per(i,a,b) for(int i=a;i <= b;i++)
#define max(a,b) a=max(a,b)
#define min(a,b) a=min(a,b)
#define sz(x) (int)x.size()
typedef long long ll;
ll gcd(ll a,ll b){while(b){ll t=b;b=a%b;a=t;}return a;}
const int inf=0x3f3f3f3f;
const int mod=1000000007;
#define siz 1005
int n,s;
double dp[siz][siz];

int main()
{
    scanf("%d%d",&n,&s);
    dp[n][s]=0.0;
    for(int i=n;i>=0;i--){
        for(int j=s;j>=0;j--){
            if(i==n&&j==s)continue;
            dp[i][j]=(n*s+(n-i)*j*dp[i+1][j]+i*(s-j)*dp[i][j+1]+(n-i)*(s-j)*dp[i+1][j+1])/(n*s-i*j);
        }
    }
    printf("%.6f\n",dp[0][0]);
    return 0;
}