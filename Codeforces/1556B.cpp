#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
int n;
int check(vector <int> a,int first_){
  int cnt = 0;
  int ret = 0;
  int now = 0;
  for (auto s:a){
    if (s==first_){
      ret = ret + abs(now-cnt);
      cnt = cnt+2;
    }
    now++;
  }
  return ret;
}
void solve(){
  cin>>n;
  vector <int> a;
  a.resize(n);
  for (int i=1;i<=n;i++) cin>>a[i-1];
  for (auto &s:a) s = s%2;

  if (n%2==0){
    int cnt = 0;
    for(auto s:a) if (s%2==0) cnt++;
    if (cnt!=n/2) {
      cout<<"-1\n";return;
    }
    int ans = 0x3f3f3f3f3f3f3f3f;
    ans = min(ans,check(a,0));
    ans = min(ans,check(a,1));
    cout<<ans<<"\n";
    return;
  } else {
    int cnt = 0;
    for (auto s:a) if (s%2==0) cnt++;
    int ans;
    if (cnt == n/2) ans = check(a,1); else if (cnt == n/2+1)  ans = check(a,0); else {cout<<"-1\n"; return;}
    cout<<ans<<"\n";
  }
  
}
signed main(){
  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin>>T;
  while(T--)solve();
}