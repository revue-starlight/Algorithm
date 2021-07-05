#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=2e5+100;
ll a[maxn];
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll T;
    cin>>T;
    while (T--){
        ll n;
        cin>>n;
        ll tot=0;
        for (ll i=1;i<=n;i++){
            cin>>a[i];
        }
        for (ll i=n;i>=2;i--){
            if (a[i]<a[i-1]) tot+=a[i-1]-a[i];
        }
        cout<<tot<<endl;
    }
    return 0;
}