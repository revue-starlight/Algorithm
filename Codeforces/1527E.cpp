#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 3.5e4+100, K = 105;
const ll MAXX = 0x3f3f3f3f3f3f3f3f;
ll tree[N*4],lazy[N*4],dp[K][N],s[N];
inline int lson(int x){return x<<1;}
inline int rson(int x){return x<<1|1;}
void build(int x,int l,int r){
    if (l==r){
        tree[x]=s[l];
        lazy[x]=0;
        return;
    }
    int mid=(l+r)>>1;
    build(lson(x),l,mid);
    build(rson(x),mid+1,r);
    tree[x]=min(tree[lson(x)],tree[rson(x)]);
    lazy[x]=0;
}

void pushdown(int x,int l,int r){
    tree[x]=tree[x]+lazy[x];
    if (l!=r){
        lazy[lson(x)]+=lazy[x]; lazy[rson(x)]+=lazy[x];
    }
    lazy[x]=0;
}

void updateRange(int x,int l,int r,int L,int R,int val){
    if (L>R) return;
    pushdown(x,l,r);
    if (l>r || l>R || r<L) return;
    if (L<=l && r<=R){
        tree[x]+=val;
        lazy[lson(x)]+=val; lazy[rson(x)]+=val;
        return;
    } 
    int mid = (l+r)>>1;
    updateRange(lson(x),l,mid,L,R,val);
    updateRange(rson(x),mid+1,r,L,R,val);
    tree[x]=min(tree[lson(x)],tree[rson(x)]);
}

ll queryRange(int x,int l,int r,int L,int R){
    pushdown(x,l,r);
    if (l>r || l>R || r<L) return MAXX;
    if (L<=l && r<=R) return tree[x];
    int mid = (l+r)>>1;
    return min(queryRange(lson(x),l,mid,L,R),queryRange(rson(x),mid+1,r,L,R));   
}

void solve(){
    int n,k;
    scanf("%d%d",&n,&k);
    int a[n+1];
    for (int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    int dp[k+1][n+1];
    int last[n+1];
    map<int,int>mp;
    for (int i=1;i<=n;i++){
        if (mp.find(a[i])==mp.end()) last[i]=0;
        else last[i]=mp[a[i]];
        mp[a[i]]=i;
    }
    dp[1][1]=0;
    for (int i=2;i<=n;i++){
        dp[1][i]=dp[1][i-1];
        if (last[i])
            dp[1][i]+=(i-last[i]);
    }

    for (int seg=2;seg<=k;seg++){
        for (int j=1;j<=n;j++) s[j]=dp[seg-1][j];
        build(1,1,n);
        for (int j=1;j<seg;j++) dp[seg][j]=MAXX;
        dp[seg][seg]=0;

        for (int j=seg+1;j<=k;j++){
            if (last[j]>seg) 
                updateRange(1,1,n,seg-1,last[j]+1,j-last[j]);
            dp[seg][j]=queryRange(1,1,n,1,j);
        }
    }
    printf("%lld\n",dp[n][k]);
}
int main(){
    solve();
    return 0;
}