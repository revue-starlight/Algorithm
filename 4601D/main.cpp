#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
int T;

int isnotprime[1005]={1,1};
int prime[1000];
int tot = 0;
vector <int> bucket[10005];
int mul(int a,int b,int mod){
    int res = 0;
    while (b){
        if (b&1) res = (res+a)% mod;
        a = (a+a)%mod;
        b>>=1;
    }
    return res;
}
ll pow(ll a,ll b,ll p){
    ll res = 1,k = a;
    while (b){
        if (b&1) res = mul(res,k,p)%p;
        k = mul(k,k,p);
        b>>=1;
    }
    return res % p;
}

bool MR(ll n, int s){
    if (n==2) return 1;
    if (n<2 || !(n&1)) return 0;
    int t = 0;
    ll x,y,u=n-1;
    while ((u&1)==0) t++,u>>=1;
    for (int i=0;i<s;i++){
        ll a = rand()%(n-1)+1;
        ll x = pow(a,u,n);
        for (int j=0;j<t;j++){
            ll y = mul(x,x,n);
            if (y==1 && x!=1 && x!=n-1) return 0;
            x = y;
        }
        if (x!=1) return 0;
    }
    return 1;
}

void init(){
    for (int i=2;i<100;i++){
        if (!isnotprime[i]){
            prime[++tot]=i;
        }
        for (int j=1;j<=tot && prime[j]*i<100;j++){
            isnotprime[prime[j]*i] = 1;
            if (i%prime[j]==0) break;
        }
    }
    int n = tot;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            for (int k=1;k<=n;k++){
                for (int l=1;l<=n;l++){
                    for (int p=1;p<=n;p++){
                        bucket[prime[i]+prime[j]+prime[k]+prime[l]+prime[p]]={prime[i],prime[j],prime[k],prime[l],prime[p]};
                    }
                }
            }
        }
    }
}

int n;
int tt = 0;
void solve(){
    tt++;
    cin>>n;
    cout<<"Case "<<tt<<": ";
    if (n<=11){
        cout<<"IMPOSSIBLE\n";
    }
    for (int p=10;p<485;p++){
        if (bucket[p].size()>0 && MR(n-p,10)==1){
           
            cout<<n-p<<" ";
            for (auto s:bucket[p]){
                cout<<s<<" ";
            }
            cout<<"\n";
            return;
        }
    }
}
signed main(){
    init();
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--) solve();
}