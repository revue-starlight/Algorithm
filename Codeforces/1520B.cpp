#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while (T--){
        int n,k;
        cin>>n;
        k = n;
        int cnt = 0;
        int ans=0;
        while (k>=10){
            k=k/10;
            cnt++;
        }
        ans+=cnt*9;
        int cmp = k;
        for (int i=1;i<=cnt;i++){
            cmp = cmp*10+k;
        }
        if (cmp<=n){
            ans+=k;
        }
        else ans+=k-1;
        cout<<ans<<"\n";
    }
    return 0;
}