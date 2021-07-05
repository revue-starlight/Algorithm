#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;
void solve(){
    int s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    int ss1 = max(s1,s2),ss2=max(s3,s4);
    int ff1 = min(s1,s2),ff2=min(s3,s4);
    if (ss1<ff2 || ss2<ff1 ) cout<<"NO\n"; else cout<<"YES\n";
}
signed main(){
    cin>>T;
    while (T--) solve();
    return 0;
}