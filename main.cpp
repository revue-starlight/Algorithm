#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3+10;
int T;
int sg[N];
int dfs(int n){
    if (sg[n]!=-1) return sg[n];
    if (n==1) return sg[n] = 0;
    vector <int> vec;
    int xorr = 0;
    for (int i=1;i<=sqrt(n);i++){
        if (n%i == 0) {vec.push_back(i);
            if (i*i!=n && i!=1) vec.push_back(n/i);
        }

    }
    int vis[N];
    memset(vis,0,sizeof(vis));

    for (auto s:vec){
        xorr ^= dfs(s);
    }
    for (auto s:vec){
        vis[xorr^sg[s]] = 1;
    }

    for (int i=0;i<1001;i++){
        if (!vis[i]) return sg[n] = i;
    }
    return 0;
}
void solve(){
    memset(sg,-1,sizeof(sg));
    int n,m;
    while (cin>>n){
        int ret = 0;
        for (int i=1;i<=n;i++){
            int x;
            cin>>x;
            ret ^= dfs(x);
        }
        if (ret == 0) cout<<"rainbow\n";
        else cout<<"freda\n";
    }
}
signed main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //cin>>T;
    T = 1;
    while(T--)solve();
}