#include <bits/stdc++.h>
using namespace std;
int T;
int diff[100005];
int t1[100005];
int s0[100005];
void solve(){
    int len;
    cin>>len;
    string s,t;
    cin>>s>>t;
    int p = 0;
    s+="0";
    t+="0";
    s=" "+s;
    t=" "+t;
    diff[len+2]=0;
    for (int i=len+1;i>=1;i--) diff[i]=diff[i+1]+(s[i]!=t[i]);
    for (int i=1;i<=len+1;i++) t1[i]=t1[i-1]+(t[i]=='1');
    for (int i=1;i<=len+1;i++) s0[i]=s0[i-1]+(s[i]=='0');
    int ans = diff[1];
    for (int i=1;i<=len+1;i++){
        ans = min(ans,s0[i-1]+t1[i-1]+1+(t[i]=='0')+(s[i]=='1')+diff[i+1]);
    }
    cout<<ans<<endl;
}
int main(){
    // freopen("data.in","r",stdin);
    // freopen("test.out","w",stdout);
    cin>>T;
    while (T--) solve();
}