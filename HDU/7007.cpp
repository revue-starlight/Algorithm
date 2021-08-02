#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;
const int N = 1e5+10;
int a[N];
void solve(){
    int n,m;
    cin>>n>>m;
    int x = 0;
    int now = 0;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        now = now+a[i];
    }
    for (int i=1;i<=n;i++){
        x = x+a[i];
        if (x>=m){
            cout<<1<<"\n";
            return;
        }
        if (x<0) x=0;
    }
    int tmp = x;
    int delta = -1;
    for (int i=1;i<=n;i++){
        x+=a[i];
        if (x>=m){
            cout<<2<<"\n";
            return;
        }
        delta = max(delta,x-tmp);
    }
    if (now<=0) {cout<<"-1\n"; return;}
    int cha = x - tmp;
    int newm = m - delta - tmp;
    int tmp1 = 0;
    if (newm%cha!=0) tmp1+=1;
    tmp1+=newm/cha;
    int ans = tmp1+2;
    cout<<ans<<endl;
}
signed main(){
    //freopen("data.in","r",stdin);
    //freopen("test.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while (T--) solve();
}