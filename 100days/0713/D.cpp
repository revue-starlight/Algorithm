#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;
int a[200005];
void solve(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    vector <int> ans;
    ans.push_back(0);
    for (int i=2;i<=n;i++){
        int k = a[i-1];
        int p=0;
        int anss = 0;
        while ((1<<p)<=k){
            if (((1<<p)&k)!=0){
                if (((1<<p)&a[i])==0){
                    a[i]=a[i]^(1<<p);
                    anss^=(1<<p);
                }
            }
            p++;
        }
        ans.push_back(anss);
    }
    for (auto s:ans){
        cout<<s<<" ";
    }
    cout<<endl;
}
signed main(){
    cin>>T;
    while (T--) solve();
    return 0;
}