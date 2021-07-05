#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;
int main(){
    string s;
    cin>>s;
    ll len=s.length();
    ll ya=0,n=0;
    for (ll i=0;i<len;i++){
        if (i+1<len && s[i]=='y' && s[i+1]=='a'){
            ya++;
        }
        if (s[i]=='n') n++;
    }
    ll originalya=ya,originaln=n;
    ll l;
    cin>>l;
    string ppp;
    cin>>ppp;
    for (ll i=0;i<l;i++){
        char ch = ppp[i];
        if (ch=='n'){
            n+=ya;
            ya=0;
            n%=mod;
        }
        else{
            ya+=n;
            ya%=mod;
        }
    }
    ll ans = (len+mod*4-originaln-originalya*2+ya*2+n)%mod;
    cout<<ans<<endl;
    return 0;
}