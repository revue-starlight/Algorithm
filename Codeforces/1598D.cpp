#include <bits/stdc++.h>
using namespace std;
map <int,int> mp[2];
void solve(){
    int n;
    cin>>n;
    vector <pair<int,int>> vec;
    mp[0].clear(); mp[1].clear();
    for (int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        vec.push_back(make_pair(x,y));
        mp[0][x]++;
        mp[1][y]++;
    }
    int ans = n*(n-1)*(n-2)/6;
    for (auto s:vec){
        ans -= (mp[0][s.first]-1)*(mp[1][s.second]-1);
    }
    cout<<ans<<"\n";
}
int main(){
    int T;
    cin>>T;
    while (T--) solve();
}