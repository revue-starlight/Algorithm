#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=2e5+10;
const ll ssxs=-1e10;
ll a[maxn];
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll T;
    cin>>T;
    while (T--){
        ll n,k;
        cin>>n>>k;
        ll maxx=ssxs;
        for (ll i=1;i<=n;i++) {cin>>a[i]; if (a[i]>maxx) maxx=a[i];}
        ll maxx2=ssxs;
        for (ll i=1;i<=n;i++) {a[i]=maxx-a[i]; if (a[i]>maxx2) maxx2=a[i];}
        if (k==1){
            for (int i=1;i<=n;i++) cout<<a[i]<<" ";
            cout<<endl;
            continue;
        }
        else{
            if (k%2==0){
                for (int i=1;i<=n;i++) cout<<maxx2-a[i]<<" ";
                cout<<endl;
            }
            else{
                for (int i=1;i<=n;i++) cout<<a[i]<<" ";
                cout<<endl;
            }
        }
    }
    return 0;
}