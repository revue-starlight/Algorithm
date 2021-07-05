#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+100;
ll n;
ll a[N];
map <ll,ll> mp;
bool bo[N];
int main(){
    memset(bo,0,sizeof(bo));
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    mp[0]=0+1;
    ll tmp=0;
    ll maxl=0;
    for (int i=1;i<=n;i++) {
        a[i]+=a[i-1];
        if (mp[a[i]]){
            maxl=max(maxl,mp[a[i]]);
        }
        tmp+=i-maxl;
        mp[a[i]]=i+1;
    }
    cout<<tmp;
}