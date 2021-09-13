#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5+100;
int T;
int n,m,k;
int x[N],y[N];
pair <int,int> p[N];
void solve(){
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++) cin>>x[i];
    for (int i=1;i<=m;i++) cin>>y[i];
    for (int i=1;i<=k;i++) cin>>p[i].first>>p[i].second;
    sort(x+1,x+1+n);sort(y+1,y+1+m);sort(p+1,p+1+k);
    int pp = 1;
    int ans = 0;
    for (int i=2;i<=n;i++){
        int nowhave = 0;
        int sum = 0;
        map <int,int> mp;
        while (pp<=k && p[pp].first==x[i-1]) pp++;
        while (pp<=k && p[pp].first<x[i]){
            mp[p[pp].second]++;
            pp++;
        }
        map<int,int>::iterator iter = mp.begin();
        while (iter!=mp.end()){
            sum+=iter->second*nowhave;
            nowhave+=iter->second;
            iter++;
        }
        ans+=sum;
    }
    for (int i=1;i<=k;i++) swap(p[i].first,p[i].second);
    sort(p+1,p+1+k);
    pp = 1;
    for (int i=2;i<=m;i++){
        int nowhave = 0;
        int sum = 0;
        map <int,int> mp;
        while (pp<=k && p[pp].first==y[i-1]) pp++;
        while (pp<=k && p[pp].first<y[i]){
            mp[p[pp].second]++;
            pp++;
        }
        map<int,int>::iterator iter = mp.begin();
        while (iter!=mp.end()){
            sum+=iter->second*nowhave;
            nowhave+=iter->second;
            iter++;
        }
        ans+=sum;
    }
    cout<<ans<<"\n";
}
signed main(){
    cin>>T;
    while (T--) solve();
}