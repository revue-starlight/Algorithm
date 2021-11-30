#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
#define int long long
const int N = 1e5+10;
int T; 
int n;
int k;
struct SuffixArray{
    int sa[N],ht[N],rk[N];
    int s[N];
    int cnt[N],oldrk[N<<1],id[N],px[N];
    int len,m,w,i,p,k;
    void read(int _n){
      for (int i=1;i<=_n;i++) scanf("%lld",s+i);
      len = _n;
    }
    bool cmp(int x,int y,int w){
        return oldrk[x]==oldrk[y] && oldrk[x+w] == oldrk[y+w];
    }
    void build(){
        m = max(len,300ll);
        memset(cnt,0,sizeof(cnt));
        for (i=1;i<=len;i++) cnt[rk[i]=s[i]]++;
        for (i=1;i<=m;i++) cnt[i]+=cnt[i-1];
        for (i=len;i>=1;i--) sa[cnt[rk[i]]--]=i;
        for (w=1;;w<<=1,m=p){
            for (i=len,p=0;i>len-w;--i) id[++p] = i;
            for (i=1;i<=len;i++)
                if (sa[i]>w) id[++p]=sa[i]-w;
            memset(cnt,0,sizeof(cnt));
            for (i=1;i<=len;i++) cnt[px[i]=rk[id[i]]]++;
            for (i=1;i<=m;i++) cnt[i]+=cnt[i-1];
            for (i=len;i>=1;i--) sa[cnt[px[i]]--]=id[i];

            memcpy(oldrk,rk,sizeof(rk));
            for (p=0,i=1;i<=len;i++) 
                rk[sa[i]] = cmp(sa[i],sa[i-1],w)?p:++p;
            if (p==len){
                for (i=1;i<=len;++i) sa[rk[i]]=i;
                break;
            }
        }
    }
    void getht(){
        for (i=1,k=0;i<=len;++i){
            if (k) --k;
            while (s[i+k] == s[sa[rk[i]-1]+k]) ++k;
            ht[rk[i]] = k;
        }
    }
}sa;


bool check(int mid,int n){
    int cnt = 1;
    int l,r;
    l = 0,r = -1;
    for (int i=2;i<=n;i++){
      if (sa.ht[i]<mid){
        cnt = 1;
      } else {
        cnt++;
        if (cnt>=k) return true;
      }
    }
    return false;
}

void solve(){
    cin>>n>>k;
    sa.read(n);
    sa.build();
    sa.getht();
    int l = 1,r = n,ans=0;
    while (l<=r){
        int mid = (l+r)>>1;
        if (check(mid,n)){
            ans = mid;
            l = mid+1;
        } else r = mid-1;
    }
    printf("%lld\n",ans);
    for (int i=1;i<=n;i++) sa.ht[i]=0;
    for (int i=1;i<=n;i++) sa.sa[i]=0;
    for (int i=1;i<=n;i++) sa.rk[i]=0;
    for (int i=1;i<=n;i++) sa.s[i]=0;
}
signed main(){
  solve();
}