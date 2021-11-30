#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
#define int long long
const int N = 1e5+10;
int T; 
int n;
struct SuffixArray{
    int sa[N],ht[N],rk[N];
    int s[N];
    int cnt[N],oldrk[N<<1],id[N],px[N];
    int len,m,w,i,p,k;
    void read(int _n){
        int ret; 
        scanf("%lld",&ret);
        int ret2;
        for (int i=2;i<=_n;i++){
            scanf("%lld",&ret2);
            s[i-1] = ret2-ret+100;
            ret = ret2;
        }
        len=_n-1;
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
    int cnt = 0;
    int l,r;
    l = 0,r = -1;
    for (int i=2;i<=n;i++){
        if (cnt>=mid) return true;
        if (sa.ht[i]<mid) {
            l = 0x3f3f3f3f3f3f3f3f;
            r = -r;
            continue;
        }
        l = min(l,min(sa.sa[i-1],sa.sa[i]));
        r = max(r,max(sa.sa[i-1],sa.sa[i]));
        cnt = max(r-l,cnt);
    }
    if (cnt>=mid) return true;
    return false;
}

void solve(int n){
    sa.read(n);
    sa.build();
    sa.getht();
    int l = 1,r = n/2,ans=-1;
    while (l<=r){
        int mid = (l+r)>>1;
        if (check(mid,n-1)){
            ans = mid;
            l = mid+1;
        } else r = mid-1;
    }
    printf("%lld\n",ans+1);
    for (int i=1;i<=n;i++) sa.ht[i]=0;
    for (int i=1;i<=n;i++) sa.sa[i]=0;
    for (int i=1;i<=n;i++) sa.rk[i]=0;
    for (int i=1;i<=n;i++) sa.s[i]=0;
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        
    while(cin>>n){
        if (n==0) return 0;
        solve(n);
    }
}