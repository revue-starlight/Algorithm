#include <bits/stdc++.h>
using namespace std;
#define ll long long
map <ll,ll> mp;
const int N =1e5+100;
ll a[N];
int main(){
    int T;
    cin>>T;
    while (T--){
        int n;
        cin>>n;
        mp.clear();
        ll ans = 0;
        for (int i=1;i<=n;i++){
            cin>>a[i];
            ans += (mp[a[i]]*(n-i+1));
            mp[a[i]]+=(i);
        }
        cout<<ans<<endl;
    }
    return 0;
}