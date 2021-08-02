#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;
void solve(){
    int n;
    cin>>n;
    if (n<=6) cout<<"15\n";
    else  {if (n%2) n++;
    cout<<n/2*5<<endl;}
}
signed main(){
    cin>>T;
    while (T--) solve();
    return 0;
}