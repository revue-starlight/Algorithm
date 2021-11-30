#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
const int N = 2e5+100;
const int mod = 1e9+7;
int fpow (int a, int b) { 
  if (b<0) return 0;
  int ret = 1; while (b) { if (b & 1) ret = 1ll * ret * a % mod; a = 1ll * a * a % mod; b >>= 1; } return ret; }
struct Node{
  int l,r,v;
  const bool operator < (const Node &rhs) const {
    return l<rhs.l;
  }
}a[N];
int in[30];
struct N2{
  int id,r;
  const bool operator < (const N2 &rhs) const {
    return r>rhs.r;
  }
};#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
const int N = 2e5+100;
const int mod = 1e9+7;
int fpow (int a, int b) { 
  if (b<0) return 0;
  int ret = 1; while (b) { if (b & 1) ret = 1ll * ret * a % mod; a = 1ll * a * a % mod; b >>= 1; } return ret; }
struct Node{
  int l,r,v;
  const bool operator < (const Node &rhs) const {
    return l<rhs.l;
  }
}a[N];
int in[30];
struct N2{
  int id,r;
  const bool operator < (const N2 &rhs) const {
    return r>rhs.r;
  }
};

void work(int id,int op){
  for (int i=0;i<30;i++){
    in[i]+=((((a[id].v)>>i)&1)^1)*op;
  }
}

int ans[N];
int numof1[30];
void solve(){
  memset(numof1,0,sizeof(numof1));
  memset(in,0,sizeof(in));
  priority_queue <N2> q;
  int n,m;
  cin>>n>>m;
  for (int i=1;i<=m;i++){
    cin>>a[i].l>>a[i].r>>a[i].v;
  }
  for (int i=1;i<=n;i++) ans[i]=0;
  sort(a+1,a+1+m);
  int cnt = 1;
  int now = pow(2,30)-1;
  for (int i=1;i<=n;i++){
    while (a[cnt].l == i){
      work(cnt,1);
      q.push({cnt,a[cnt].r});
      cnt++;
    }
    while (q.top().r==i-1){
      work(q.top().id,-1);
      q.pop();
    }
    for (int j=0;j<30;j++){
      ans[i] += (in[j]==0) * (1<<j);
    }
  }  
  int ret  = 0;
  for (int i=1;i<=n;i++){
    for (int j=0;j<30;j++){
      numof1[j]+=((ans[i]>>j)&1);
    }
  }
  
  for (int j=0;j<30;j++){
    ret += ((fpow(2,numof1[j]-1) * fpow(2,n-numof1[j]) % mod) * (1<<j))% mod;
    ret %= mod;
  }
  cout<<ret<<"\n";
}
signed main(){
  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin>>T;
  while(T--)solve();
}

void work(int id,int op){
  for (int i=0;i<30;i++){
    in[i]+=((((a[id].v)>>i)&1)^1)*op;
  }
}

int ans[N];
int numof1[30];
void solve(){
  memset(numof1,0,sizeof(numof1));
  memset(in,0,sizeof(in));
  priority_queue <N2> q;
  int n,m;
  cin>>n>>m;
  for (int i=1;i<=m;i++){
    cin>>a[i].l>>a[i].r>>a[i].v;
  }
  for (int i=1;i<=n;i++) ans[i]=0;
  sort(a+1,a+1+m);
  int cnt = 1;
  int now = pow(2,30)-1;
  for (int i=1;i<=n;i++){
    while (a[cnt].l == i){
      work(cnt,1);
      q.push({cnt,a[cnt].r});
      cnt++;
    }
    while (q.top().r==i-1){
      work(q.top().id,-1);
      q.pop();
    }
    for (int j=0;j<30;j++){
      ans[i] += (in[j]==0) * (1<<j);
    }
  }  
  int ret  = 0;
  for (int i=1;i<=n;i++){
    for (int j=0;j<30;j++){
      numof1[j]+=((ans[i]>>j)&1);
    }
  }
  
  for (int j=0;j<30;j++){
    ret += ((fpow(2,numof1[j]-1) * fpow(2,n-numof1[j]) % mod) * (1<<j))% mod;
    ret %= mod;
  }
  cout<<ret<<"\n";
}
signed main(){
  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin>>T;
  while(T--)solve();
}