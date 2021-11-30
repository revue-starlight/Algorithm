#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
const int N = 1e6+100;
int a[N],b[N];
void solve(){
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=n;i++){
        cin>>b[i];
    }
    sort(b+1,b+1+n);
    
    
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--)solve();
}