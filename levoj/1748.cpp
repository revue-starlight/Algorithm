#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
vector <int> a,b,c,d;
unordered_map <int,int> mp;
void solve(){
    mp.clear();
    a.clear();
    b.clear();
    c.clear();
    d.clear();
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        int x,y,z,p;
        cin>>x>>y>>z>>p;
        a.push_back(x);
        b.push_back(y);
        c.push_back(z);
        d.push_back(p);
    }
    for (auto aa:a){
        for (auto ss:b){
            mp[aa+ss]++;
        }
    }
    int ans = 0;
    for (auto aa:c){
        for (auto bb:d){
            ans +=  mp[-(aa+bb)];
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--)solve();
}