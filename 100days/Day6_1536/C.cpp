#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+100;
map <pair<int,int>, int> mp;
char a[N];
int num[N];
int T;
void solve(){
    int n;
    cin>>n;
    mp.clear();
    for (int i=1;i<=n;i++){
        cin>>a[i];
        num[i]=0;
    }
    int d=0,k=0;
    for (int i=1;i<=n;i++){
        if (a[i]=='D') d++; else k++;
        int gcd = __gcd(d,k);
        pair <int,int> pr = {d/gcd,k/gcd};
        int now = 1;
        if (mp.find(pr)!=mp.end()){
            now = mp[pr] +1;
        }
        num[i]=now;
        mp[pr]=now;
        cout<<now<<" ";
    }
    cout<<endl;
}
signed main(){
    cin>>T;
    while (T--) solve();
    return 0;
}