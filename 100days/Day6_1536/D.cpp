#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
int T;
set <int> s;
int a[N];
void solve(){
    s.clear();
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    s.insert(a[1]);
    for (int i=2;i<=n;i++){
        int prv = a[i-1];
        if (prv!=a[i]){
            if (prv<a[i]){
                auto it = s.upper_bound(prv);
                if (it!=s.end() && *(it)<a[i]){
                    cout<<"NO\n";
                    return;
                }
            }
            if (prv>a[i]){
                auto it = s.lower_bound(prv);
                if (it!=s.begin() && (*(--it)>a[i])){
                    cout<<"NO\n";
                    return;
                }
            }
            s.insert(a[i]);
        }
        
    }
    cout<<"YES\n";
}
signed main(){
    cin>>T;
    while (T--) solve();
    return 0;
}