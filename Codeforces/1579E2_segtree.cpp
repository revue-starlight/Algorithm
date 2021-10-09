#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int rnk[N],a[N];
unordered_map <int,int> to;
int tree[N<<2];
int lazy[N<<2];
void pushdown(int x,int l,int r){
    if (lazy[x]==1){
        lazy[x<<1]=lazy[x<<1|1]=1;
        tree[x<<1]=tree[x<<1|1]=0;
        lazy[x]=0;
    }
}

void upd2(int x,int l,int r,int id){
    pushdown(x,l,r);
    if (l==r){
        tree[x]+=1;
        return;
    }
    int mid = (l+r)>>1;
    if (id<=mid) upd2(x<<1,l,mid,id);
    else upd2(x<<1|1,mid+1,r,id);
    tree[x]=tree[x<<1]+tree[x<<1|1];
}
int query(int x,int l,int r,int L,int R){
    if (L>R) return 0;
    pushdown(x,l,r);
    if (l==r){
        return tree[x];
    }
    int mid = (l+r)>>1;
    int ret = 0;
    if (L<=mid) ret+=query(x<<1,l,mid,L,R);
    if (R>mid) ret+=query(x<<1|1,mid+1,r,L,R);
    return ret;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin>>T;

    while (T--){
        int n;
        to.clear();
        cin>>n;
        for (int i=1;i<=n;i++){
            cin>>a[i]; rnk[i]=a[i];
        }
        sort(rnk+1,rnk+1+n);
        int newn = unique(rnk+1,rnk+1+n) - rnk; newn--;
        for (int i=1;i<=newn;i++){
            to[rnk[i]]=i;
        }
        int tot = 0;
        tree[1]=0; lazy[1]=1;        
        for (int i=1;i<=n;i++){
            int aa = query(1,1,newn,1,to[a[i]]-1);
            int bb = query(1,1,newn,to[a[i]]+1,newn);
            tot+=min(aa,bb);
            upd2(1,1,newn,to[a[i]]);
        }
        cout<<tot<<"\n";
    }
}