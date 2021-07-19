#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;
void solve(){
    int n,a,b;
    string s;
    int v=1;
    cin>>n>>a>>b;
    cin>>s;
    for (int i=1;i<s.length();i++){
        int pre=s[i-1]-'0';
        int now=s[i]-'0';
        if (pre^now==1) v++;
    }
    if (b>0){
        int len = s.length();
        int ans = (a+b)*len;
        cout<<ans<<endl;
    } else {
        int timess = v/2+1;
        int len = s.length();
        int coutt = a*len+b*timess;
        cout<<coutt<<endl;
    }

}
signed main(){
    cin>>T;
    while (T--) solve();
    return 0;
}