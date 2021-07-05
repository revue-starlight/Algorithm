#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;
void solve(){
    int n;
    cin>>n;
    if (n%2==0){
        for (int i=1;i<=n/2;i++){
            cout<<i*2<<" "<<i*2-1<<" ";
        }
    }
    else {
        n-=3;
        for (int i=1;i<=n/2;i++){
            cout<<i*2<<" "<<i*2-1<<" ";
        }
        n+=3;
        cout<<n-1<<" "<<n<<" "<<n-2;
    }
    cout<<endl;
}
signed main(){
    cin>>T;
    while (T--) solve();
    return 0;
}