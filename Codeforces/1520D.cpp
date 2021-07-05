#include <bits/stdc++.h>
using namespace std;
#define ll long long
map <ll,ll> mp;
const ll N = 2e5+15;
ll a[N];
int main(){
    ll T;
    cin>>T;
    while (T--){
       ll n;
       cin>>n;
       mp.clear();
       for (ll i=1;i<=n;i++){
           cin>>a[i];
       }
       ll ans=0;
       for (ll i=1;i<=n;i++){
           ans+=mp[a[i]-i];
           mp[a[i]-i]++;
       }
       cout<<ans<<endl;
    }
    return 0;
}