#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+10;
int T;
int n;
char s[N];
int n, sa[N], rk[N], oldrk[N << 1], id[N], px[N], cnt[N];
int height[N];
int a[N];
bool cmp(int x,int y,int w){return oldrk[x]==oldrk[y] && oldrk[x+w]==oldrk[y+w];}

void geiHeight(){
    for (int i=1,k=0;i<=n;i++){
        if(k!=0) k--;
        while (s[i+k] == s[sa[rk[i]-1] + k]) ++k;
        height[rk[i]] = k;
    }
}

void getSA(int *a){
    int i,m=300,p,w;
    memset(cnt,0,sizeof(cnt));
    for (int i=1;i<=n;i++) ++cnt[rk[i]=a[i]];
    for (int i=1;i<=m;i++) cnt[i]+=cnt[i-1];
    for (int i=n;i>=1;i--) s#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+10;
int T;
int n;
char s[N];
int n, sa[N], rk[N], oldrk[N << 1], id[N], px[N], cnt[N];
int height[N];
int a[N];
bool cmp(int x,int y,int w){return oldrk[x]==oldrk[y] && oldrk[x+w]==oldrk[y+w];}

void geiHeight(){
    for (int i=1,k=0;i<=n;i++){
        if(k!=0) k--;
        while (s[i+k] == s[sa[rk[i]-1] + k]) ++k;
        height[rk[i]] = k;
    }
}

void getSA(int *a){
    int i,m=300,p,w;
    memset(cnt,0,sizeof(cnt));
    for (int i=1;i<=n;i++) ++cnt[rk[i]=a[i]];
    for (int i=1;i<=m;i++) cnt[i]+=cnt[i-1];
    for (int i=n;i>=1;i--) sa[cnt[rk[i]]--]=i;
    for (int w=1;;w<<=1,m=p){
        for (p=0,i=n;i>n-w;i--) id[++p]=i;
        for (int i=1;i<=n;i++){
            if (sa[i]>w)
                id[++p]=sa[i]-w;
        }
        memset(cnt,0,sizeof(cnt));
        for (int i=1;i<=n;i++) cnt[px[i]=rk[id[i]]]++;
        for (int i=1;i<=m;i++) cnt[i]+=cnt[i-1];
        for (int i=n;i>=1;i--) sa[cnt[px[i]]--] = id[i];
        
        memcpy(oldrk,rk,sizeof(rk));
        for (p=0, i=1;i<=n;i++){
            rk[sa[i]] = cmp(sa[i],sa[i-1],w)?p:++p;
        }
        if (p==n){
            for (int i=1;i<=n;i++){
                sa[rk[i]]=i;
                break;
            }
        }
    }
}

void solve(){
    for (int i=1;i<=n;i++) cin>>a[i];
    
    
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    while(cin>>n && n!=0)solve();
}a[cnt[rk[i]]--]=i;
    for (int w=1;;w<<=1,m=p){
        for (p=0,i=n;i>n-w;i--) id[++p]=i;
        for (int i=1;i<=n;i++){
            if (sa[i]>w)
                id[++p]=sa[i]-w;
        }
        memset(cnt,0,sizeof(cnt));
        for (int i=1;i<=n;i++) cnt[px[i]=rk[id[i]]]++;
        for (int i=1;i<=m;i++) cnt[i]+=cnt[i-1];
        for (int i=n;i>=1;i--) sa[cnt[px[i]]--] = id[i];
        
        memcpy(oldrk,rk,sizeof(rk));
        for (p=0, i=1;i<=n;i++){
            rk[sa[i]] = cmp(sa[i],sa[i-1],w)?p:++p;
        }
        if (p==n){
            for (int i=1;i<=n;i++){
                sa[rk[i]]=i;
                break;
            }
        }
    }
}

void solve(){
    for (int i=1;i<=n;i++) cin>>a[i];
    
    
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    while(cin>>n && n!=0)solve();
}