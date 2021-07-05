#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k;
const ll N = 1e6+100;
ll a[N];
ll L[N],R[N];
ll l,r;
ll C(ll p,ll remainK){
    ll ans = 1;
    ll tmp = 0;
    if (p<remainK) return 0;
    for (int i=p;i>p-remainK;i--){
        tmp ++;
        ans *= i;
        ans /= tmp;
    }
    return ans;
}
ll check(string s){
    ll len = s.length();
    s = " "+s;
    ll ans = 0;
    ll remainK = k;
    for (ll i=1;i<=len;i++){
        if (s[i]=='1'){
            remainK;
            ll p = len-i;
            if (remainK<0) return ans;
            ans += C(p,remainK);
            remainK--;
        }
    }
    int cnt = 0;
    for (int i=1;i<=s.length();i++){
        if (s[i]=='1') cnt++;
    }
    if (cnt==k) ans++;
    return ans;
}
int flag = 0;
ll calc(string s){
    int ret = 0;
    for (int i=0;i<s.length();i++){
        if (s[i]=='1') ret++;
    }
    if ((ret==k) && flag==1) return 1; else return 0;
}

int main(){
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    cin>>l>>r;
    string s,t;
    s="";
    t="";
    ll tmp = l;
    for (int i=n;i>=1;i--){//找到最大的小于等于l的数字
        if (tmp-a[i]>=0) s+="1",tmp-=a[i];
        else s+="0";
    }
    tmp = r;
    for (int i=n;i>=1;i--){//找到最大的小于等于r的数字
        if (tmp-a[i]>=0) t+="1",tmp-=a[i];
        else t+="0";
    }
    if (tmp == 0) flag = 1;
    //cout<<s<<"\n"<<t<<"\n";
    ll retl = check(s);
    ll retr = check(t);
    cout<<retr-retl+calc(s)<<endl;
    return 0;
}