#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;
struct QUERY{
    int val,Ll,Lr,Rl,Rr;
}a[N];
int T;
int dpL[N],dpR[N];
bool getRestrict(int pos,int type,int Rid){
    if (!type){
        return (a[Rid].Ll<= a[pos].val)&&(a[pos].val<=a[Rid].Lr);
    } else {
        return (a[Rid].Rl<= a[pos].val)&&(a[pos].val<=a[Rid].Rr);
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i].val>>a[i].Ll>>a[i].Lr>>a[i].Rl>>a[i].Rr;
    }
    for (int i=0;i<=n+1;i++) dpL[i]=dpR[i]=0;
    dpL[n] = getRestrict(n,0,n),dpR[n] = getRestrict(n,1,n);
    int lastl=-1, lastr = -1;
    if (!dpL[n]) lastl = n;
    if (!dpR[n]) lastr = n;
    for (int i=n-1;i>=1;i--){
        {// dpL
            
        }
        {// dpR
            if (lastl!=-1){

            }
        }
    }
}
signed main(){
    cin>>T;
    while (T--) solve();
    return 0;
}