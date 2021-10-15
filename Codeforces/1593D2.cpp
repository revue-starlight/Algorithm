#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+100;
short isnotprime[N];
int prime[N],tot,from[N];
unordered_map <int,int> mp;
void init(){
    isnotprime[0]=isnotprime[1]=1;
    for (int i=2;i<=2e6+100;i++){
        if (isnotprime[i]==0){
            prime[++tot]=i;
        }
        for (int j=1;j<=tot && prime[j]*i<=2e6;j++){
            isnotprime[prime[j]*i]=1;
            from[prime[j]*i]=j;
        }
    }
}
int a[50],b[50];
int maxx,thres;
void get_factor(int p){
    int Tsqr = sqrt(p);
    for (int i=1;i<=Tsqr;i++){
        if (i*i==p) {
            mp[Tsqr]++;
            if (mp[Tsqr]>=thres && maxx<Tsqr) maxx = Tsqr;
            break;
        }
        if (p%i==0) {
            mp[i]++;mp[p/i]++;
            if (mp[p/i]>=thres && maxx<p/i) maxx = p/i;    
            if (mp[i]>=thres && maxx<i) maxx = i;
        }
    }

}
void solve(){
    int n;
    maxx = 1;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];b[i]=a[i];
    }
    sort(a+1,a+1+n);
    int tmp = 1;
    for (int i=2;i<=n;i++){
        if (a[i]==a[i-1]){
            tmp++;
            if (tmp>=n/2){
                cout<<"-1\n";
                return;
            }
            
        }
        else tmp=1;
    }
    int i=1;
    int last = 0;
    while (i<n){
        while (i<n && a[i]==a[i+1]) i++;
        int num = i-last;
        thres = n/2-num;
        mp.clear();
        vector <int> vec;
        for (int j=i+1;j<=n;j++) vec.push_back(a[j]-a[i]);
        for (auto &s:vec){
            get_factor(s);
        }
        last = i;
        i++;
    }
    cout<<maxx<<"\n";
}

int main(){
    init();
    int T;
    cin>>T;
    while (T--) solve();
}