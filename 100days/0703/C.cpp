#include <bits/stdc++.h>
using namespace std;
#define int long long
int get(int n,int k){
    if (n==1) return 0;
    int plus = n%k;
    if (n/k == 0){
        return n-1;
    }
    return plus + get(n/k,k)+1;
}
signed main(){
    int T;
    scanf("%lld",&T);
    while (T--){
        int n,k;
        cin>>k>>n;
        int cnt;
        cnt=0;
        if (k==1){printf("%lld\n",n-1); continue;}
        while (n!=1){
            cnt += n%k;
            if (n/k==0) {cnt-=1; break;}
            cnt+=1;
            n=n/k;
        }
        printf("%lld\n",cnt);
    }
}