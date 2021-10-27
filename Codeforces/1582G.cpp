#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
const int N = 1e6+10;
int num[N],ch[N];
int prime[N],isnotprime[N];
int pre[N],divv[N];
int tot = 0;

void init(){
    isnotprime[0] = isnotprime[1] = 1;
    for (int i=2;i<N;i++){
        if (!isnotprime[i])
            prime[++tot] = i;
        for (int j=1;prime[j]*i<N;j++){
            isnotprime[prime[j]*i] = 1;
            pre[prime[j]*i] = i;
            divv[prime[j]*i] = prime[j];
            if (i%prime[j]==0) 
                break;
        }
    }
}

void handle(int x,int op){
    vector <int> gett;
    while (pre[x]!=0){
        gett.push_back(divv[x]);
        x = pre[x];
    }
    gett.push_back(x);
    for (auto s:gett)cout<<s<<" ";
    cout<<"\n";
}

void solve(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>num[i];
    }

    for (int i=1;i<=n;i++){
        char x;
        cin>>x;
        ch[i]=(x=='*')?1:0;        
    }

    for (int i=1;i<=n;i++){
        handle(num[i],ch[i]);
    }
}
signed main(){
   // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    init();
    cout<<tot<<"\n";
    cin>>T;
    while(T--)solve();
}
/* 
最多6e6个因子。
存下每个因子的增减和位置。
然后对重复的线段做一次减法。
*/