#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;
int a[200006];
void solve(){
    int n;
    cin>>n;
    int sum=0;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a+1,a+1+n);
    if (sum%n) {
        cout<<-1<<endl;
        return;
    }
    else {
        int cnt=0,pos=n;
        while (a[pos]>sum/n){
            cnt++;
            pos--;
        }
        cout<<cnt<<endl;
    }
}
signed main(){
    cin>>T;
    while (T--) solve();
    return 0;
}