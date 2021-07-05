#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;
const int N = 1e6+100;
void solve(){
    int n;
    cin>>n;
    double XX = 1e9+1;
    double YY = 1e9+1;
    for (int i=1;i<=n;i++){
        double x,y;
        cin>>x>>y;
        if (x==0){
            YY = min(YY,y);
        }
        if (y==0){
            XX = min(XX,x);
        }
    }
    if (XX == 1e9+1 || YY == 1e9+1 ){
        cout<<"Poor Little H!";
    }
    else {
        float juli = 1.0*sqrt(XX*XX+YY*YY);
        printf("%.10f",juli);
    }
}
signed main(){
    solve();
    return 0;
}