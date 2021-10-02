#include <bits/stdc++.h>
using namespace std;
int T;
int cnt = 0;
void solve(){
    int n;
    cnt++;
    cin>>n;
    string s;
    cin>>s;
    int thres = (n-1)/2;
    for (int i=0;i<n;i++){
        if (s[i]=='0'){
            int p = i+1;
            if (i<=thres){
                cout<<p<<" "<<n<<" "<<p+1<<" "<<n<<"\n";
                return;
            } else {
                cout<<1<<" "<<p<<" "<<1<<" "<<p-1<<'\n';
                return;
            }
        }
    }
    cout<<1<<' '<<n-1<<" "<<2<<" "<<n<<"\n";
    return;
}
int main(){
    cin>>T;
    while (T--) solve();
}