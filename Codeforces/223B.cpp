#include <bits/stdc++.h>
using namespace std;
string s,t;
const int N = 2e5+10;
int l[N],r[N];
int p;
int nxt[N];
int main(){
    cin>>s>>t;
    int lens = s.length(),lent=t.length();
    s = " "+s;
    t=" "+t;
    p=1;
    memset(nxt,-1,sizeof(nxt));
    for (int i=1;i<=lens;i++){
        if (s[i]==t[p]) {p++; nxt[s[i]]=p-1;}
        l[i]=nxt[s[i]];
    }
    p = lent;
    memset(nxt,-1,sizeof(nxt));
    for (int i=lens;i>=1;i--){
        if (s[i]==t[p]) {p--; nxt[s[i]]=p+1;}
        r[i]=nxt[s[i]];
    }
    int f=1;
    for (int i=1;i<=lens;i++){
        if (r[i]<0 || l[i]<0 || r[i]>l[i]) f=0;
    }
    (f==0)?cout<<"No":cout<<"Yes";
}