#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;
const int N = 1e5+100;
int a[N];
void solve(){
    int n;
    int ans=0;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for (int i=2;i<=n;i++){
        a[i]+=a[i-1];
    }
    for (int i=3;i<=n;i++){
        int now = a[i]-a[i-1];
        ans -= ((i-2)*now - a[i-2]);
    }
    cout<<ans<<endl;
}
signed main(){
    cin>>T;
    while (T--) solve();
    return 0;
}