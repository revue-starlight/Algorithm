#include <bits/stdc++.h>
using namespace std;
int T;
void solve(){
    int n;
    cin>>n;
    int x;
    x=0;
    for (int i=1;i<=n;i++){
        int p;
        cin>>p;
        x+=p;
    }
    if (x==n) {cout<<"0\n"; return;}
    if (x<n) {cout<<"1\n"; return;}
    else {cout<<x-n<<endl; return;}
}
int main(){
    cin>>T;
    while (T--) solve();
}