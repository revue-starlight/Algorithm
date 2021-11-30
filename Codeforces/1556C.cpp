#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
const int N = 1e5+10;
int a[N];
map <int,int> have;
int now = 0;
void solve(){
  memset(a,0,sizeof(a));
  have.clear();
  now = 0;
  int n;
  cin>>n;
  int ans = 0;
  for (int i=1;i<=n;i++){
    cin>>a[i];
    if (i%2==1){
      now+=a[i];
    } else {
      int newnow = max(now-a[i],0ll);
      ans += now - newnow;
      map <int,int> ::iterator iter;
      if (now-a[i]>=0){
        have[newnow]++;
        for (iter = have.begin();iter!=have.end();iter++){
          if (iter->first == newnow){
            ans+=iter->second-1;
          } else if (iter->first > newnow && iter->first < now){
            ans+=iter->second;
          }
        }
        for (iter = have.begin();iter!=have.end();){
          if (iter->first > newnow){
            iter = have.erase(iter);
          } else {
            iter++;
          }
        }
      } else {
         for (iter = have.begin();iter!=have.end();iter++){
            ans+=iter->second;
        }
        have.clear();
      }
      now = newnow;
    }
  }
  cout<<ans<<endl;
}
signed main(){
  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  //cin>>T;
  T = 1;
  while(T--)solve();
}