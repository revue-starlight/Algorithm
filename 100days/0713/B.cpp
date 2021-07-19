#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;
void solve(){
    string s;
    cin>>s;
    int ch[26];
    memset(ch,0,sizeof(ch));
    int f = 1;
    for (int i=0;i<s.length();i++){
        ch[s[i]-'a']++;
    }
    for (int i=0;i<s.length();i++){
        if (ch[i]==0) {f=0;break;}
    }
    for (int i=1;i<s.length()-1;i++){
        if (s[i-1]<s[i] && s[i+1]<s[i])  f = 0;
    }
    if (f) cout<<"YES\n"; else cout<<"NO\n";
}
signed main(){
    cin>>T;
    while (T--) solve();
    return 0;
}