#include <bits/stdc++.h>
using namespace std;
int T;
const int N = 1e5+10;
int a[N];
void solve(){
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>a[i];  
    }
    sort(a+1,a+1+n);
    int ans = n;
    int p = a[1]-k;
    for (int i=1;i<=n;i++){
        if (p<=a[i]-k) {
            p=a[i]-k;
            p++;
        }
        else {
            if (p>a[i]+k) ans--;
            else {
                p++;
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while (T--) solve();
}