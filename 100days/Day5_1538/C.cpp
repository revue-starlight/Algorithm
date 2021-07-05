#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N =2e5+100;
int a[N];
int T;
void solve(){
    int n,l,r;
    cin>>n>>l>>r;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int i=1,j=n;
    int cnt=0;
    for (int i=1;i<=n;i++){
        int now = a[i];
        int posl = lower_bound(a+1,a+1+n,l-a[i])-a;
        int posr = upper_bound(a+1,a+1+n,r-a[i])-a-1;
        if (posr == 0 && (r-a[1]<l)) continue;
        if (posl == n+1) continue;
        cnt+=(posr-posl+1);
    }
    for (int i=1;i<=n;i++) if (a[i]+a[i]<=r && a[i]+a[i]>=l) cnt--;
    cout<<cnt/2<<endl;
}
signed main(){
    cin>>T;
    while (T--) solve();
    return 0;
}