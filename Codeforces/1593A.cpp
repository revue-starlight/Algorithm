#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
void solve(){
    
    int a[3];
    cin>>a[0]>>a[1]>>a[2];
    int maxx = max_element(a,a+3)-a;
    int cnt = 0;
    for (int i=0;i<3;i++) if (a[maxx]==a[i]) cnt++;
    for (int i=0;i<3;i++){
        if (a[maxx]==a[i] && cnt==1) cout<<"0 ";
        else if (a[maxx]==a[i] && cnt>1) cout<<"1 ";
            else cout<<a[maxx]+1-a[i]<<" ";
    }
    cout<<"\n";
}
signed main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--)solve();
}