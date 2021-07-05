#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,x,t;
    cin>>n>>x>>t;
    n--;
    int p = t/x;
    if (n<=p) cout<<(n+1)*n/2<<"\n";
    else {
        int a = (p+1)*p/2;
        int b = (n-p)*p;
        cout<<a+b<<"\n";
    }

}
signed main(){
    int T;
    cin>>T;
    while (T--) solve();
}