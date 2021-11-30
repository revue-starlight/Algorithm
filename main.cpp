#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+100;
int T;
int sa[N],px[N],rk[N],oldrk[N<<1],ht[N],cnt[N],id[N],i,len,m,p,w,k;
string s;
bool cmp(int x,int y,int w){
    return (oldrk[x]==oldrk[y] && oldrk[x+w]==oldrk[y+w]);
}
void read(){
    m = 300;
    cin>>s;
    s = " "+s;
    len = s.length();
    len--;
}
void build(){
    for (i = 1; i <= len; ++i) ++cnt[rk[i] = s[i]];
  for (i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
  for (i = len; i >= 1; --i) sa[cnt[rk[i]]--] = i;
  for (w = 1;; w <<= 1, m = p) {  // m=p 就是优化计数排序值域
    for (p = 0, i = len; i > len - w; --i) id[++p] = i;
    for (i = 1; i <= len; ++i)
      if (sa[i] > w) id[++p] = sa[i] - w;
    memset(cnt, 0, sizeof(cnt));
    for (i = 1; i <= len; ++i) ++cnt[px[i] = rk[id[i]]];
    for (i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
    for (i = len; i >= 1; --i) sa[cnt[px[i]]--] = id[i];
    memcpy(oldrk, rk, sizeof(rk));
    for (p = 0, i = 1; i <= len; ++i)
      rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
    if (p == len) {
      for (int i = 1; i <= len; ++i) sa[rk[i]] = i;
      break;
    }
  }
}
void getHt(){
for (i = 1, k = 0; i <= len; ++i) {
  if (k) --k;
  while (s[i + k] == s[sa[rk[i] - 1] + k]) ++k;
  ht[rk[i]] = k;  // height太长了缩写为ht
}
}
void gc(){
    for (i=1;i<=len;++i) sa[i]=ht[i]=rk[i]=0;
}

void solve(){
    //memset(sa,0,sizeof(sa));
    //memset(px,0,sizeof(px));
    //memset(rk,0,sizeof(rk));
    // memset(oldrk,0,sizeof(oldrk));
    //memset(ht,0,sizeof(ht));
    memset(cnt,0,sizeof(cnt));
    // memset(id,0,sizeof(id));
    //i=len=m=p=w=k=0;
    read();
    build();
    getHt();
    int ans = 0;
    for (int i=2;i<=len;++i) ans += ht[i];
    ans = len*(len+1)/2 - ans;
    cout<<ans<<"\n";
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--)solve();
    return 0;
}