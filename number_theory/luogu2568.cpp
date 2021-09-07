/*
题目描述
给定正整数 n，求 1≤x,y≤n 且 gcd(x,y) 为素数的数对 (x,y) 有多少对。

输入格式
只有一行一个整数，代表n。

输出格式
一行一个整数表示答案。
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e7+10;
const int mod = 1e9+7;
const int NN = 1e7;
int prime[N],isnotprime[N],cnt,mu[N];
int sum[N];
void init(){
    isnotprime[0]=isnotprime[1]=1;
    mu[1]=1;
    for (int i=2;i<=NN;++i){
        if (!isnotprime[i]){
            prime[++cnt]=i;
            mu[i]=-1;
        }
        for (int j=1;j<=cnt;j++){
            if (prime[j]*i>NN) break;
            isnotprime[prime[j]*i]=1;
            mu[prime[j]*i]=-mu[i];
            if (i%prime[j]==0){
                mu[prime[j]*i]=0;
                break;
            }
        }
    }

    for (int i=1;i<=cnt;++i){
        for (int j=1;j<=NN;j++){
            if (prime[i]*j>NN) break;
            sum[prime[i]*j]+=mu[j];
        }
    }
    for (int i=1;i<=NN;i++){
        sum[i]+=sum[i-1];
    }
}

void solve(){
    int n;
    cin>>n;
    int l=1,r=1;
    int ans = 0;
    while (l<=n){
        r = n/(n/l);
        int len = (r-l)+1;
        ans += (n/l)*(n/l)*(sum[r]-sum[l-1]);
        l = r+1;
    }
    cout<<ans<<endl;
}

signed main(){
    init();
    solve();
}
