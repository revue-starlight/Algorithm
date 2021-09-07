#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
void solve(){
        int n;
        cin>>n;
        for (int i=1;i<=n;i++){
            cin>>a[i];
            a[i]=a[i]^1;
        }
        if (a[1]==0){
            cout<<n+1<<" ";for (int i=1;i<=n;i++)cout<<i<<" ";cout<<'\n';
            return;
        }
        if (a[n]==1){
            for (int i=1;i<=n+1;i++)cout<<i<<" ";cout<<'\n';
            return;
        }
        if (n==1 && a[1]==1){
            cout<<"1 2\n";
            return;
        }
        
        int flag = 1;
        for (int i=2;i<=n;i++){
            if (a[i]!=a[i-1]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            cout<<"-1\n";
            return;
        }
        for (int i=2;i<=n;i++){
            if (a[i]==0 && a[i-1]==1){
                for (int j=1;j<=i-1;j++){
                    cout<<j<<" ";
                }
                cout<<n+1<<" ";
                for (int j=i;j<=n;j++) cout<<j<<" ";
                cout<<"\n";
                return;
            }
        }

        cout<<n+1<<" ";
        for (int j=1;j<=n;j++) cout<<j<<" ";

        cout<<"\n";
        return;
        
}
int main(){
    int T;
    cin>>T;
    while (T--){
        solve();
    }
}