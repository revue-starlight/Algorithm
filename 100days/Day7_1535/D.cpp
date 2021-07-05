#include <bits/stdc++.h>
using namespace std;
const int N = 3e5;
int a[N<<3];
int main(){
    int n,q;
    cin>>n;
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    s=" "+s;
    int st = pow(2,n);
    for (int i=st;i<st+st;i++) a[i]=1;
    for (int i=st-1;i>=1;i--) {
        if (s[i]=='1') a[i]=a[i*2];
        if (s[i]=='0') a[i]=a[i*2+1];
        if (s[i]=='?') a[i]=a[i*2]+a[i*2+1];
    }
    cin>>q;
    while (q--){
        int pos; char q;
        cin>>pos>>q;
        pos = st - pos;
        s[pos]=q;
        while (pos){
            int i=pos;
            if (s[i]=='1') a[i]=a[i*2];
            if (s[i]=='0') a[i]=a[i*2+1];
            if (s[i]=='?') a[i]=a[i*2]+a[i*2+1];
            pos = pos/2;
        }
        cout<<a[1]<<endl;
    }
    return 0;
}