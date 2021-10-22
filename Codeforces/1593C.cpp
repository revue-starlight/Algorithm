#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
void solve(){
    int n,m;
    cin>>n>>m;
    int a[m+1];
    for (int i=1;i<=m;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+m);
    int cat_pos = 0;
    int ans = m;
    for (int i=m;i>=1;i--){
        if (cat_pos>=a[i]){
            ans = m - i;
            break;
        } else {
            cat_pos+=n-a[i];
        }
    }
    cout<<ans<<"\n";
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--)solve();
}