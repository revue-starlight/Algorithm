#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+100;
int n;
int a[N][6];
int check(int ii,int jj){
    int zz = 0;
    int xx=0 ,yy= 0;
    for (int i=1;i<=n;i++){
        if (a[i][ii]&&a[i][jj]) zz++;
        else if (a[i][ii]) xx++;
        else if (a[i][jj]) yy++;
    }
    if (xx+yy+zz>=n && xx+zz>=n/2 && yy+zz>=n/2) return 1;
    else return 0;
}
void solve(){
    cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=5;j++) cin>>a[i][j];
    }
    for (int i=1;i<=5;i++){
        for (int j=i+1;j<=5;j++){
            if (check(i,j)){
                cout<<"Yes\n"; return;
            }
        }
    }
    cout<<"No\n";

}
signed main(){
    int T;
    cin>>T;
    while (T--){
        solve();
    }
    return 0;
}