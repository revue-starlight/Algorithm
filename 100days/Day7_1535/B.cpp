#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;
void solve(){
    int n;
    cin>>n;
    int a[n],b[n];
    int cnt=0;
    for (int i=0;i<n;i++) cin>>a[i];
    for (int i=0;i<n;i++){
        if (a[i]%2==1) b[cnt++]=a[i];
    }
    for (int i=0;i<n;i++){
        if (a[i]%2==0) b[cnt++]=a[i];
    }
    cnt=0;
    for (int i=n-1;i>=0;i--){
        for (int j=i-1;j>=0;j--){
            if (__gcd(b[i],b[j]*2)>1) cnt++;
        }
    }
    cout<<cnt<<endl;
}
signed main(){
    cin>>T;
    while (T--) solve();
    return 0;
}