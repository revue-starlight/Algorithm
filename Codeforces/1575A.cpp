#include <bits/stdc++.h>
using namespace std;
const int N = 10000;
int tot;
int minn;
int minnid;
int n;
void solve(){
    cin>>n;
    tot = 0;
    minn = numeric_limits<int>::max();
    for (int i=1;i<=n;i++){
        int x;
        cin>>x;
        if (x<minn && minn%2==1){
            minn = x;
            minnid = i;
        }
        tot+=x;
    }
    if (tot%2==0){
        for (int i=1;i<=n;i++){
            cout<<i<<" ";
        }
    } else {
        for (int i=1;i<=n;i++){
            if (minnid == i){
                continue;
            }
            cout<<i<<" ";
        }
    }
}
int main(){
    int T;
    cin>>T;
    while (T--) solve();   
    return 0;
}