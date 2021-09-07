#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,k1,k2,k3,a,b,c;
    cin>>n>>k1>>k2>>k3>>a>>b>>c;
    double dp[n+k1+k2+k3+30][2];
    memset(dp,0,sizeof(dp));
    double p = 1 / k1 / k2 / k3;
    for (int i=n-1;i>=1;i--){
        for (int k01=1;k01<=k1;k01++){
            for (int k02=1;k02<=k2;k02++){
                for (int k03=1;k03<=k3;k03++){
                    int add = k01+k02+k03;
                    if (k01==a && k02==b && k03==c){
                        dp[i][0]+=p;
                    } else {
                        dp[i][0]+=dp[i+add][0]*p;
                        dp[i][1]+=p*dp[i+add][1];
                    }
                }
            }
        }
        dp[i][1]+=1;
    }
    double tmp1,tmp2;
    for (int k01=1;k01<=k1;k01++){
            for (int k02=1;k02<=k2;k02++){
                for (int k03=1;k03<=k3;k03++){
                    int add = k01+k02+k03;
                    if (!(k01==a && k02==b && k03==c)){
                        tmp1+=dp[add][0];   
                        tmp2+=dp[add][1];
                } 
            }
        }
    }
    double ans = (tmp2*p+1)/(1-p-tmp1*p);
    cout<<ans<<"\n";
}
int main(){
    int T;
    cin>>T;
    while (T--) solve();
}