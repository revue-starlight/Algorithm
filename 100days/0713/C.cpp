#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;
void solve(){
    int k,m,n;
    cin>>k>>n>>m;
    int a[305],b[305];
    memset(a,0,sizeof(a)); memset(b,0,sizeof(b));

    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++) cin>>b[i];
    int p1=1,p2=1;
    int f = 1;
    int work[5000];
    int cnt = 0;
    while (p1<=n || p2<=m){
        int pp = 1;
        if (p1<=n && p2<=m && a[p1]>k && b[p2]>k){
            f=0;
            break;
        }
        if (p1<=n && a[p1]<=k){
            work[++cnt]=a[p1];
            if (a[p1]==0) k++;
            p1++;
            pp = 0;
        }
        if (p2<=m && b[p2]<=k){
            work[++cnt]=b[p2];
            if (b[p2]==0) k++;
            p2++;
            pp = 0;
        }
        if (pp) {f=0; break;}
    }
    if (f) {
        for (int i=1;i<=n+m;i++) cout<<work[i]<<' ';
        cout<<"\n";
    } else cout<<"-1\n";
}
signed main(){
    cin>>T;
    while (T--) solve();
    return 0;
}