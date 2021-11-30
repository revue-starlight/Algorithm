#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
int T;
int ksm(int a,int b){
  int ret = 1;
  while (b){
    if (b%2){
      ret = ret * a % mod;
    }
    a*=a; a%=mod;
    b>>=1;
  }
  return ret;
}
void solve(){
  int n;
  cin>>n;
  vector <int> a;
  a.resize(n+1);
  for (int i=1;i<=n;i++){
    cin>>a[i];
  }
  vector <int> b;
  b.resize(31);
  for (int i=1;i<=n;i++){
    for (int j=0;j<=30;j++){
      if ((a[i]>>j)&1){
        b[j]++;
        break;
      }
    }
  }

  vector <int> lst;
  lst.resize(32);
  lst[30]=b[30];
  for (int i=29;i>=0;i--) lst[i] = lst[i+1]+b[i];

  int ans = 0;
  ans += (ksm(2,b[0])+mod-1)%mod*ksm(2,lst[1])%mod;
  for (int j=1;j<=30;j++){
    if (b[j]>0){
      int aa = ((ksm(2,b[j]-1))%mod+mod-1)%mod;
      int bb = ksm(2,lst[j+1]);
      int tmp = (aa*bb)%mod;
      ans = ans+tmp;
      ans %= mod;
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