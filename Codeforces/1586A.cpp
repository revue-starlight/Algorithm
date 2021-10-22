#include <bits/stdc++.h>
using namespace std;
int n;
int isprime(int x){
    for (int i=2;i<=sqrt(x);i++){
        if (x%i==0) return false;
    }
    return true;
}
void solve(){
    cin>>n;
    int a[n+1];
    int tot = 0;
    int minn = 205;
    int id = -1;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        tot+=a[i];
        if (a[i]<minn && a[i]%2==1){
            minn =a[i];
            id = i;
        }
    }   
    if (!isprime(tot)){
        cout<<n<<"\n";
        for (int i=1;i<=n;i++) {
            cout<<i<<" ";
        }
        cout<<"\n";
        return;
    } else {
        cout<<n-1<<"\n";
        for (int i=1;i<=n;i++){
            if (id==i) continue;
            cout<<i<<" ";
        }
        cout<<"\n";
        return;
    }
}
int main(){
    int T;
    cin>>T;
    while (T--){
        solve();
    }
}