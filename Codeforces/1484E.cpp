#include <bits/stdc++.h>
using namespace std;
const int N = 3e5+10;
int h[N],b[N],dp[N];
struct{
    int l,r,val,lztag;
}tree[N<<2];
void pushdown(int x){
    if (tree[x].lztag==-1) return;
    tree[x<<1].val = tree[x<<1|1].val = tree[x].lztag;
    tree[x].lztag = -1;
    tree[x<<1].lztag = tree[x<<1|1].lztag = tree[x<<1].val;
}
void build(int x,int l,int r){
    tree[x].l = l;
    tree[x].r = r;
    tree[x].lztag = -1;
    if (l==r){
        tree[x].val = 0;
        return;
    }
    int mid  = (l+r)/2;
    build(x<<1,l,mid); build(x<<1|1,mid+1,r);
    tree[x].val = max(tree[x<<1].val,tree[x<<1|1].val);
}
void upd(int x,int l,int r,int L,int R,int val){
    pushdown(x);
    if (L<=l && r<=R) {
        tree[x].lztag = tree[x].val = val;
        return;
    }
    int mid = (l+r)>>1;
    if (L<=mid) upd(x<<1,l,mid,L,R,val);
    if (R>mid) upd(x<<1|1,mid+1,r,L,R,val);
    tree[x].val = max(tree[x<<1].val,tree[x<<1|1].val);
}
int query(int x,int l,int r,int L,int R){
    if (L>R) return -1;
    pushdown(x);
    if (L<=l && r<=R) return tree[x].val;
    int mid = (l+r)>>1;
    int tot = 0;
    if (l<=mid) tot =  query(x<<1,l,mid,L,R);
    if (r>mid) tot = max(tot,query(x<<1|1,mid+1,r,L,R));
    return tot;
}
stack <int> st;
int dp[N];
int main(){
    int n;
    cin>>n;
    build(1,1,n);
    for (int i=1;i<=n;i++) cin>>h[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    //強くなりたいつよくなりたいつよくなりたいつよくなりたいつよくなりたいつよくなりたいつよくなりたいつよくなりたい
    st.push(0);
    for (int i=1;i<=n;i++){
        while (!st.empty() && h[st.top()]>h[i]) st.pop();
        int maxx = -1;
        if (st.top()+1<=i-1)
            maxx = query(1,1,n,st.top()+1,i)+b[i];
        maxx = max(maxx,dp[st.top()]);
        upd(1,1,n,i,i,maxx);
        dp[i]=maxx;
    }
    return 0;
}