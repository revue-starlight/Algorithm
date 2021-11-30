#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
void solve(){
  int n;
  cin>>n;
  int ans = 0;
  vector <int> a;
  a.resize(n+1);
  for (int i=1;i<=n;i++) cin>>a[i];
  sort(a.begin()+1,a.end());
  for (int i=1;i<n;i++){
    int cnt = 2;
    int l = a[i];
    int r = a[i+1];
    int rpos = i+1;
    if (l==r){
      rpos = lower_bound(a.begin()+i,a.end(),l+1) - a.begin();
      cnt = rpos - i + 1;
      if (rpos == n+1){
        ans = max(ans,n+1-i);
        break;
      }
      r = a[rpos];
      l = a[rpos-1];
      i = rpos-1;
    }
    int ideal = r+(r-l);
    while ((rpos = lower_bound(a.begin()+rpos+1,a.end(),ideal) - a.begin()) != n+1){
      r = a[rpos];
      ideal = r+(r-l);
      cnt++;
    }
      ans = max(ans,cnt);
  }
  cout<<n-ans<<endl;
}
signed main(){
  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin>>T;
  while(T--)solve();
}