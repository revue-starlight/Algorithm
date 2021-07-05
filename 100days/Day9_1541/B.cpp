#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;
const int N = 1e5+100;
struct re{
    int val,id;
    const bool operator < (const re &b) const {
        return val<b.val;
    }
};
int a[N];
set <re> s;
void solve(){
    int n;
    s.clear();
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int cnt = 0;
    for (int i=1;i<=n;i++){
        int low = (i+1)/a[i],high = (i+i-1)/a[i];
        auto lowit = s.lower_bound({low,1});
        auto highit = s.upper_bound({high,1});
        for (auto it = lowit;it!=highit;it++){
            if (i+it->id == a[i]*it->val)
                cnt++;
        }
        s.insert({a[i],i});
    }
    cout<<cnt<<endl;
}
signed main(){
    cin>>T;
    while (T--) solve();
    return 0;
}