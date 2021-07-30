#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e7+10;
int n,m;
bool isnotprime[N];
int prime[N],cnt;
int prepri[N];
void init(){
    isnotprime[0]=isnotprime[1]=1;
    for (int i=2;i<=N;i++){
        if (!isnotprime[i]) prime[++cnt]=i;
        for (int j=1;j<=cnt && prime[j]*i<N;j++){
            isnotprime[prime[j]*i]=1;
            if (i%prime[j]==0) break;
        }
    }
}
void solve(){
    int n;
    cin>>n;
    int q = n/2;    
    int posr = upper_bound(prime+1,prime+1+cnt,n)-prime-1;
    int ans = prepri[posr] - 2ll + (n+3)*(n-2)/2;
    cout<<ans<<endl;
}
signed main(){
    int T;
    cin>>T;
    init();
    for (int i=1;i<N;i++){
        prepri[i]=prepri[i-1]+prime[i];
    }
    while (T--) solve();
}