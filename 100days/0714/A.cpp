#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;
void solve(){
    unordered_set<int> s;
    int n;
    cin>>n;
    int p = 1;
    int sum = 0;
    int cnt = 0;
    while (sum<=n){
        sum+=p;
        p+=2;
        cnt++;
        if (sum==n) break;
    }
    cout<<cnt<<endl;
}
signed main(){
    cin>>T;
    while (T--) solve();
    return 0;
}