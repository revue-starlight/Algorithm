#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;
void solve(){
    int x,y;
    cin>>x>>y;
    if (x<y) swap(x,y);
    if (x==y){
        cout<<"0 0\n";
        return;
    }
    int dlt = x-y;
    int p = y / dlt;
    int x1 = abs(p*dlt-y);
    int x2 = abs((p+1)*dlt-y);
    cout<<dlt<<" "<<min(x1,x2)<<endl;
}
signed main(){
    cin>>T;
    while (T--) solve();
    return 0;
}