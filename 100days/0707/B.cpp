#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;
const int N = 2e5+100;
    int a[N];
void solve(){
    int n;
    cin>>n;
    int sum = 0;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    int p = sum / n;
    int remain = sum % n;
    int avg = n - remain;
    cout<<avg*remain<<endl;
}
signed main(){
    cin>>T;
    while (T--) solve();
    return 0;
}