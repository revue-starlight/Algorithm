#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
void solve(){

  int a,b;
  cin>>a>>b;
  if (a==b && a==0){
    cout<<0<<endl;
    return;
  }
  if (abs(a-b)==0){
    cout<<1<<endl;
  } else if (abs(a-b)%2==0){
    cout<<2<<endl;
  } else if (abs(a-b)%2==1){
    cout<<-1<<endl;
  }
  
}
signed main(){
  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin>>T;
  while(T--)solve();
}