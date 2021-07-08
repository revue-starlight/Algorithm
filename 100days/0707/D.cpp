#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;
void solve(){
    int n,k;
    cin>>n>>k;
    int x = 0;
    for (int i=0;i<n;i++){
        int p = i;
        cout<<x<<endl;
        int ans;
        cin>>ans;
        if (ans == 1) return;
        x = p^(p+1);
    }
}
signed main(){
    cin>>T;
    while (T--) solve();
    return 0;
}