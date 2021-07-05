#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
struct node{
    int l,r,sum;
}e[N<<5];
int tree_cnt,rt[N],n,a[N],q;
int add(int l,int r,int pre,int k){
    tree_cnt++;
    int pos=tree_cnt;
    if (l==r){
        e[pos].sum=1;
        return pos;
    }
    e[pos]=e[pre];
    int mid=(l+r)>>1;
    if (k<=mid) e[pos].l=add(l,mid,e[pre].l,k);
    else e[pos].r=add(mid+1,r,e[pre].r,k);
    e[pos].sum=e[e[pos].l].sum+e[e[pos].r].sum;
    return pos;
}

int query(int l,int r,int tl,int tr,int rt1,int rt2){
    if (tl<=l && r<=tr) return e[rt1].sum-e[rt2].sum;
                                                                                  
}
int main(){
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        query()
    }   
}