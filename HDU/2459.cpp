#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
const int N = 1000010;
char s[N];
char revs[N];
int n,sa[N],rk[N<<1],oldrk[N<<1],id[N],cnt[N];
int ht[N];
int revsa[N],revht[N];


int st[20][N],revst[20][N];


void getST(int *ht){
    for (int i=1;i<=n;i++){
        st[i][0] = ht[i];
    }
    int lev = 1;
    for (int k=2;k<=n;k<<=1){
        for (int i=k;i<=n;i++){
            st[i][lev] = min(st[i][lev-1],st[i-k+1][lev-1]);
        }
    }
}

void getSA(char *s,int *sa,int *ht){
    
    int i,m,p,w;
    m = max(n,300ll);
    for (int i=1;i<=n;++i) ++cnt[rk[i]=s[i]];
    for (int i=1;i<=m;++i) cnt[i]+=cnt[i-1];
    for (int i=n;i>=1;--i) sa[cnt[rk[i]]--]=i;
    for (w=1;w<n;w<<=1){
        memset(cnt,0,sizeof(cnt));
        for (int i=1;i<=n;++i) id[i]=sa[i];
        for (int i=1;i<=n;++i) ++cnt[rk[id[i]+w]];
        for (int i=1;i<=m;++i) cnt[i]+=cnt[i-1];
        for (int i=n;i>=1;--i) sa[cnt[rk[id[i]+w]]--] = id[i];
        memset(cnt,0,sizeof(cnt));
        for (int i=1;i<=n;i++) id[i]=sa[i];
        for (int i=1;i<=n;i++) ++cnt[rk[id[i]]];
        for (int i=1;i<=m;i++) cnt[i]+=cnt[i-1];
        for (int i=n;i>=1;i--) sa[cnt[rk[id[i]]]--] = id[i];
        memcpy(oldrk,rk,sizeof(rk));
        for (p=0,i=1; i<=n; ++i){
            if (oldrk[sa[i]] == oldrk[sa[i-1]] && oldrk[sa[i]+w] == oldrk[sa[i-1]+w]){
                rk[sa[i]] = p;
            } else {
                rk[sa[i]] = ++p;
            }
        }
    }
    int k = 0;
    for (i = 1, k = 0; i <= n; ++i) {
        if (k) --k;
        while (s[i + k] == s[sa[rk[i] - 1] + k]) ++k;
        ht[rk[i]] = k;  // height太长了缩写为ht
    }
    getST(ht);
}

int getLcp(int (*st)[N],int ll,int rr){
    rr-=1;
    int k = log2(rr-ll+1);
    return min(st[k][ll],st[k][rr-k+1]); 
}

void solve(){
    scanf("%s",s+1);
    strcpy(revs+1,s);
    n = strlen(s);
    revs[n]='\0';
    getSA(s,sa,ht);
    getSA(s,revsa,revht);
    int maxx = 0;
    for (int i=2;i<n/2;i++){
        for (int j=1+i;j<=n;j+=i){
            int ll = j-i, rr = j;
            int x = getLcp(st,ll,rr);
            int revll,revrr;
            revrr = (n+1)-(ll-1);
            revll = (n+1)-(rr-1);
            int y = getLcp(revst,ll,rr);
            maxx = max(maxx,(x+y+i)/i);
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--)solve();
}