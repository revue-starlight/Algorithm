/*
    1.不爽不要写题目
    2.题目不清晰不要写题目
    3.变量最好放到一个东西里
    4.复用的时候一行一行改
    5.二叉树开到*8，求求您了
    6.lazyTag也带着一起清，求求你了，清完好不好
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+100;
struct TREE{
    int max,min;
}t[N<<3];
int n;
int lazy[N<<3];
int ans[N],a[N];
vector <int> vec[N];

inline int lson(int x) {return x<<1;}
inline int rson(int x){ return x<<1|1;}
inline void build(int x,int l,int r){
    if (l==r){
        t[x]={a[l],a[l]};
        return;
    }
    int mid = (l+r)>>1;
    build(lson(x),l,mid); build(rson(x),mid+1,r);
    t[x]={max(t[lson(x)].max,t[rson(x)].max),min(t[lson(x)].min,t[rson(x)].min)};
}

void pushDown(int x){
    if (lazy[x]!=0){
        t[lson(x)].max+=lazy[x];
        t[lson(x)].min+=lazy[x];
        lazy[lson(x)]+=lazy[x];
        
        t[rson(x)].max+=lazy[x];
        t[rson(x)].min+=lazy[x];
        lazy[rson(x)]+=lazy[x];
        lazy[x]=0;
    }
}

void update(int x,int l,int r,int L,int R,int val){
    if (l>r) return;
    pushDown(x);
    if (L<=l && r<=R){
        lazy[x]+=val;
        t[x].max+=val;
        t[x].min+=val;
        return;
    } 
    int mid = (l+r)>>1;
    if (L<=mid) 
        update(lson(x),l,mid,L,R,val);
    if (R>mid)
        update(rson(x),mid+1,r,L,R,val);
    t[x]={max(t[lson(x)].max,t[rson(x)].max),min(t[lson(x)].min,t[rson(x)].min)};
}


inline int queryMX(int x,int l,int r,int L,int R){
    if (l>r) return numeric_limits<int>::min();
    pushDown(x);
    if (L<=l && r<=R){
        return t[x].max;
    } else {
        int mid = (l+r)>>1;
        int aa = numeric_limits<int>::min();
    if (L<= mid) 
        aa = max(aa,queryMX(lson(x),l,mid,L,R));
    if (R>mid)
        aa = max(aa,queryMX(rson(x),mid+1,r,L,R));
        return aa;
    }
}


inline int queryMN(int x,int l,int r,int L,int R){
    if (l>r) return numeric_limits<int>::max();
    pushDown(x);
    if (L<=l && r<=R){
        return t[x].min;
    } else {
        int mid = (l+r)>>1;
        int aa = numeric_limits<int>::max();
    if (L<=  mid) 
        aa = min(aa,queryMN(lson(x),l,mid,L,R));
    if (R>mid)
        aa = min(aa,queryMN(rson(x),mid+1,r,L,R));
        return aa;
    }
}

signed main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        int x;
        cin>>x;
        vec[x].push_back(i);
    }
    for (int i=0;i<=n;i++) a[i]=i;
    build(1,0,n);
    for (int i=1;i<=n;i++) ans[i]=numeric_limits<int>::min();
    // R+M-L+1
    for (int i=1;i<=n;i++){
        for (auto e:vec[i]){
            ans[e] = max(ans[e],(queryMX(1,0,n,e,n)-queryMN(1,0,n,0,e-1))/2);
        }
        for (auto e:vec[i]){
            update(1,0,n,e,n,-2);
        }
    }
    
    for (int i=0;i<N;i++) a[i]=i;
    memset(lazy,0,sizeof(lazy));
    build(1,0,n);
    // L+M-R
    for (int i=n;i>=1;i--){
        for (auto e:vec[i]){
            ans[e] = max(ans[e],(queryMX(1,0,n,e,n)-queryMN(1,0,n,0,e-1)-1)/2);
        }
        for (auto e:vec[i]){
            update(1,0,n,e,n,-2);
        }
    }
    for (int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}