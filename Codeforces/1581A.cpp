#include <bits/stdc++.h>
using namespace std;
#define int long long
int T,n;
const int mod = 1e9+7;
const int N = 1e5;
void solve(){
    int n;
    cin>>n;
    int t = 1;
    for (int i=3;i<=2*n;i++){
        t = t*i;
        t%=mod;
    }
    cout<<t<<"\n";
}
signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>T;
    while (T--) solve();
}