#include <bits/stdc++.h>
using namespace std;
int a[105],n;
bool dp[200500];
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
        int p =a[1];
        for (int i=1;i<=n;i++){
            p=__gcd(p,a[i]);
        }
        for (int i=1;i<=n;i++){
            a[i]=a[i]/p;
        }
        int sum=0;
        for (int i=1;i<=n;i++){
            sum+=a[i];
        }
        if (sum%2!=0){
            cout<<"0\n"; return 0;
        }
        else{
            int sum=0;
            for (int i=1;i<=n;i++) sum+=a[i];
            sum=sum/2;      
            for (int i=1;i<=sum+1;i++) dp[i]=false;
            dp[0]=true;
            for (int i=1;i<=n;i++){
                for (int j=sum;j>=a[i];j--){
                    if (dp[j]==true || dp[j-a[i]]==true)
                        dp[j]=true;
                }
            }
            if (dp[sum]==0) {
                cout<<"0\n";
                return 0;
            } 
            for (int i=1;i<=n;i++){
                if (a[i]%2!=0){
                    cout<<"1\n"<<i<<"\n";
                    return 0;
                }
            }
    }
}