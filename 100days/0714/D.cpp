#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;
int n,l,r;

void C(int n,int m){
    
}
void solve(){
    cin>>n>>l>>r;
    int bottoml,bottomr,topl,topr;
    bottoml = l-n,bottomr = r-n;
    topl = l-1,topr=r-1;
    int x1 = topl,x2=bottomr;
    int k1 = min(abs(x1),abs(x2));
    int ans = 0;
    // k1 * C(n,n/2);
    
    // 
    int stuffed=0;
    for (int k=k1+1;k;k++){
        if (k>bottomr) {
            stuffed++;
        }
        if (k>abs(topl)){
            stuffed++;
        }
        int remain = n-stuffed;
        int havepos = k - abs(topl);
        int haveneg = k - bottomr;
        if (n%2){
            if (havepos>n/2+1 || haveneg>n/2+1) break;
            ans += C(remain,n/2-havepos);
            ans += C(remain,n/2+1-havepos);
        } else {
            if (havepos>n/2 || haveneg>n/2) break;
            ans += C(remain,n/2-havepos);
        }
    }
}
signed main(){
    cin>>T;
    while (T--) solve();
    return 0;
}