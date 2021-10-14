#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+100;
#define int long long
int a[N];
map <double,int> mp;
void solve(){
    mp.clear();
    int n;
    cin>>n;
    int tot = 0;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]]++;
        tot+=a[i];
    }
    tot/=n;
    int ans = 0;
    for (auto s:mp){
        if (s.first == tot){
            ans+=(s.second*(s.second-1))/2;
        } else {
            if (mp.find(tot*2-s.first)!=mp.end() && s.first<tot){
                ans+=(s.second)*(*mp.find(tot*2-s.first)).second;
            }
        }
    }
    cout<<ans<<"\n";
}
signed main(){
    int T;
    cin>>T;
    while (T--) solve();
}