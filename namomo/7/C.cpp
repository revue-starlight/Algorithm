#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=100005;
const ll inf=0x3f3f3f3f3f3f3f3f;
unordered_map <ll,ll> mp;
unordered_map <ll,ll> tot;
ll a[N],vis[N];

int main(){
    ll n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=n;i++){
        ll x=a[i],t=0;
        bool bo=false;
        while (1){

            if (!bo){
                ll tx=x,tt=t;
                while (tx<=N){
                    mp[tx]++; tot[tx]+=tt;
                    tx*=tx;
                    tt++;
                    if (x==1) break; 
                }
            }
            if (x==1) break;
            if (floor(sqrt(x))*floor(sqrt(x))==x) bo=true; else bo=false;
            x=sqrt(x);
            t++;
        }
    }
    unordered_map <ll,ll>::iterator iter;
    ll anss=inf;
    for (iter=mp.begin();iter!=mp.end();iter++){
        if (iter->second==n) anss=min(anss,tot[iter->first]);
    }
    cout<<anss<<endl;
}