#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin>>T;
    while (T--){
        int n;
        cin>>n;
        int t=0;
        cin>>t;
        int tot=1;
        for (int i=2;i<=n;i++){
            int x;
            cin>>x;
            if (x==t) tot++;
        }
        if (tot==n) cout<<n<<endl;
            else cout<<1<<endl;
    }
}