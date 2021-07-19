#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;
const int N = 1e6;
int a[N];
void solve(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans = n+(n-1);
    for (int i=1;i<=n;i++){
        int r = i+2;
        if (r>n) break;
        if (!((a[i]<=a[i+1] && a[i+1]<=a[i+2]) || (a[i]>=a[i+1] && a[i+1]>=a[i+2]) )) ans++;
    }
    for (int i=1;i<=n;i++){
        int r = i+3;
        if (r>n) break;
        if (!( (a[i]<=a[i+1] && a[i+1]<=a[i+2]) || (a[i]>=a[i+1] && a[i+1]>=a[i+2]) 
            || (a[i]<=a[i+1] && a[i+1]<=a[i+3]) || (a[i]>=a[i+1] && a[i+1]>=a[i+3])
            || (a[i]<=a[i+2] && a[i+2]<=a[i+3]) || (a[i]>=a[i+2] && a[i+2]>=a[i+3])
            || (a[i+1]<=a[i+2] && a[i+2]<=a[i+3]) || (a[i+1]>=a[i+2] && a[i+2]>=a[i+3])
            )) ans++;
    }
    cout<<ans<<endl;
}
signed main(){
    cin>>T;
    while (T--) solve();
    return 0;
}