#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;
int a[100];
int a1[100],a2[100];
int n,k;
int inv(int n){
    int cnt = 0;
    while (n){
        a[++cnt]=n%k;
        n/=k;
    }
    int ret = 0;
    n=cnt;
    for (int i=1;i<=n;i++) a[i]=(k-a[i])%k;
    for (int i=n;i>=1;i--) ret = ret*k + a[i];
    return ret;
}

int work(int a,int b){
    if (a<b) swap(a,b);
    int cnt1=0,cnt2=0;
    while (a){
        a1[++cnt1]=a%k;
        a/=k;
    }
    while (b){
        a2[++cnt2]=b%k;
        b/=k;
    }
    for (int i=cnt2+1;i<=cnt1;i++) a2[i]=0;
    int ret = 0;
    for (int i=1;i<=cnt1;i++) a2[i]=(a1[i]+a2[i])%k;
    for (int i=cnt1;i>=1;i--) ret = ret*k + a2[i];
    return ret;
}
void solve(){
    cin>>n>>k;
    int x = 0;
    for (int i=0;i<n;i++){
        int p = i;
        cout<<x<<endl;
        int ans;
        cin>>ans;
        if (ans == 1) return;
        x = work(inv(p),(p+1));
    }
}

signed main(){
    cin>>T;
    while (T--) solve();
    return 0;
}