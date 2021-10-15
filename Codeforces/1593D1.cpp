#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[41];
unordered_set <int> mp;
void solve(){
    int minn1 = numeric_limits<int>::max();
    int minn2 = numeric_limits<int>::max();
    int MAXK = 1;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i]; 
        if (a[i]<minn1){
            minn2 = minn1;
            minn1 = a[i];
        } else if (a[i]<minn2 && a[i]!=minn1){
            minn2 = a[i];
        }
    }
    MAXK = minn2 - minn1;
    for (int k=MAXK;k>=1;k--){
        mp.clear();
        for (int i=1;i<=n;i++){
            mp.insert((a[i]-minn1)%k);
        }
        if (mp.size()==1){
            cout<<k<<"\n";
            return;
        }
    }    
}
signed main(){
    int T;
    cin>>T;
    while (T--) solve();   
}