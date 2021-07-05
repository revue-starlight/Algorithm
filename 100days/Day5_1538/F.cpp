#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;


int work2(int x,int cnt){
    cnt--;
    int y = x;
    while (cnt){
        cnt--;
        x=x*10+y;
    }
    return x;
}
int work(int x){
    int cnt = 0;
    int ret = 0;
    while (x){
        cnt++;
        int p;
        ret+=work2(x%10,cnt);
        x/=10;
    }
    return ret;
}
void solve(){
    int  l,r;
    cin>>l>>r;
    cout<<work(r)-work(l)<<endl;;
}
signed main(){
    cin>>T;
    while (T--) solve();
    return 0;
}