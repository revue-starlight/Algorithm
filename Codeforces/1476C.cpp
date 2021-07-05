#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5+100;
long long a[N],b[N],c[N],dp[N];
int main(){
    long long T;
    cin>>T;
    while (T--){
        long long n;
        cin>>n;
        for (long long i=1;i<=n;i++){
            cin>>c[i];
        }
        for (long long i=1;i<=n;i++){
            cin>>a[i];
        }
        for (long long i=1;i<=n;i++) {cin>>b[i]; if (b[i]<a[i]) swap(a[i],b[i]);}
        dp[2] = c[2]-1+b[2]-a[2]+2;
        long long maxx = dp[2];
        for (long long i=3;i<=n;i++){
            if (a[i]==b[i]){
                dp[i]=(c[i]-1)+2;
            }
            else {
                dp[i]=dp[i-1]-(b[i]-a[i])+c[i]+1;
                dp[i]=max(dp[i],b[i]-a[i]+c[i]+1);
            }
            maxx =max(dp[i],maxx);
        }
        cout<<maxx<<"\n";
    }
}