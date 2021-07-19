#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;
void solve(){
    int x1,x2,y1,y2,p1,p2;
    cin>>x1>>x2>>y1>>y2>>p1>>p2;
    int res=0;
    if (x1==y1 && p1==x1){
        int a = min(x2,y2);
        int b = max(x2,y2);
        if (a<p2 && p2<b) res=2;
    }
    if (x2==y2 && p2==x2){
        int a = min(x1,y1);
        int b = max(x1,y1);
        if (a<p1 && p1<b) res=2;
    }
    cout<<abs(y1-x1)+abs(y2-x2)+res<<endl;
}
signed main(){
    cin>>T;
    while (T--) solve();
    return 0;
}