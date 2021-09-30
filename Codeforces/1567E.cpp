#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
struct Node{
    int l,r,val,Lv,Rv;
}tree[N<<3];
int a[N];
void build(int x,int l,int r){
    tree[x].l=l; tree[x].r=r; // the length of Non-Decreasing subarrays of Lnode and Rnode
    if (l==r){
        tree[x].val = tree[x].Lv = tree[x].Rv = 1;
        return;
    }
    int mid = (l+r)/2;
    build(x<<1,l,mid); build(x<<1|1,mid+1,r);
    tree[x].val = tree[x<<1].val+tree[x<<1|1].val;
    if (a[tree[x<<1].r]<=a[tree[x<<1|1].l]){
        tree[x].val+=tree[x<<1].Rv*tree[x<<1|1].Lv;
    } 
    if (tree[x<<1].Lv == 1+tree[x<<1].r-tree[x<<1].l && a[tree[x<<1].r]<=a[tree[x<<1|1].l]){
        tree[x].Lv=tree[x<<1].Lv+tree[x<<1|1].Lv;
    } else {
        tree[x].Lv = tree[x<<1].Lv;
    }
    if (tree[x<<1|1].Rv == 1+tree[x<<1|1].r-tree[x<<1|1].l && a[tree[x<<1].r]<=a[tree[x<<1|1].l]){
        tree[x].Rv = tree[x<<1].Rv + tree[x<<1|1].Rv;
    } else {
        tree[x].Rv = tree[x<<1|1].Rv;
    }
}

void modify(int x,int pos,int val){
    int l=tree[x].l, r=tree[x].r;
    if (l==r){
        a[l]=val;
        tree[x].val = tree[x].Lv = tree[x].Rv = 1;
        return;
    }
    int mid = (l+r)/2;
    if (pos<=mid) modify(x<<1,pos,val); else modify(x<<1|1,pos,val);
    tree[x].val = tree[x<<1].val+tree[x<<1|1].val;
    if (a[tree[x<<1].r]<=a[tree[x<<1|1].l]){
        tree[x].val+=tree[x<<1].Rv*tree[x<<1|1].Lv;
    } 
    if (tree[x<<1].Lv == 1+tree[x<<1].r-tree[x<<1].l && a[tree[x<<1].r]<=a[tree[x<<1|1].l]){
        tree[x].Lv=tree[x<<1].Lv+tree[x<<1|1].Lv;
    } else {
        tree[x].Lv = tree[x<<1].Lv;
    }
    if (tree[x<<1|1].Rv == 1+tree[x<<1|1].r-tree[x<<1|1].l && a[tree[x<<1].r]<=a[tree[x<<1|1].l]){
        tree[x].Rv = tree[x<<1].Rv + tree[x<<1|1].Rv;
    } else {
        tree[x].Rv = tree[x<<1|1].Rv;
    }
}

int Rangequery(int x,int L,int R){
    int l = tree[x].l,r=tree[x].r;
    if (L<=l && r<=R) return tree[x].val;
    else {
        int mid = (l+r)/2;
        int ret = 0;
        if (L<=mid)
            ret += Rangequery(x<<1,L,R);
        if (R>mid)
            ret += Rangequery(x<<1|1,L,R);
        if (L<=mid && R>mid && a[tree[x<<1].r]<=a[tree[x<<1|1].l]){
            ret += tree[x<<1|1].Lv*tree[x<<1].Rv;
        }
        return ret;
    }
}
void solve(){
    int n,q;
    cin>>n>>q;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    for (int i=1;i<=q;i++){
        int type,l,r;
        cin>>type>>l>>r;
        if (type==1){
            modify(1,l,r);
        } else {
            cout<<Rangequery(1,l,r)<<endl ;
        }
    }
}
int main(){
    solve();
}