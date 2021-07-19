#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;
void solve(){
    int n;
    cin>>n;
    string s = to_string(n);
    int maxx = -1;
    for (int i=0;i<s.length();i++){
        int p = s[i]-'0';
        maxx= max(p,maxx);
    }
    cout<<maxx<<endl;
}
signed main(){
    cin>>T;
    while (T--) solve();
    return 0;
}