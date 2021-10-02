#include <bits/stdc++.h>
using namespace std;
#define int long long
int T,n;
const int N = 1e5;
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    int ans;
    if (m<n-1){
        cout<<"NO\n";
        return;
    }
    if (m>n*(n-1)/2){
        cout<<"NO\n";
        return;
    }

    ans = 0;
    if (n==1){
        if (m==0) ans = 0;
    }
    else {
        if (m==n*(n-1)/2){
        ans = 1;
        }
        else ans = 2;
    }
    if (k-1>ans) cout<<"YES\n";
    else cout<<"NO\n";

}
signed main(){
   // ios::sync_with_stdio(false); cin.tie(0);
    cin>>T;
    while (T--) solve();
}