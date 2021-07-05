#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5;
ll a[N],rk[N],n,m,p,tree_cnt;
struct Node{
    ll l,r,sum;
}tree[N>>5];
ll rt[N]; //第i个树的根vb
void build(ll pos,ll l,ll r){
    if (l==r) return;
    ll mid = (l+r)>>1;
    tree[pos].l=tree_cnt+1;
    build(++tree_cnt,l,mid);
    tree[pos].r=tree_cnt+1;
    build(++tree_cnt,mid+1,r);
}

ll modify(ll root,ll l,ll r){//对某个节点进行操作
    ll tmp = ++tree_cnt; //新建某个节点
    tree[tmp].l=tree[root].l; tree[tmp].r=tree[root].r;  tree[tmp].sum=tree[root].sum+1; //对此节点赋值,先与之前保持同步，再做出修改
    if (l==r) return tmp; 
    ll mid = (l+r)>>1;
    if (p<=mid) tree[tmp].l=modify(tree[root].l,l,mid);
    else tree[tmp].r=modify(tree[root].r,mid+1,r);
    return tmp;
}

ll query(ll tree1,ll tree2,ll l,ll r,ll k){
    ll ans,mid=((l+r)>>1),x=tree[tree[tree2].l].sum-tree[tree[tree1].l].sum;//左节点最后一名排多少
    if (l==r){//区间为1时直接返回，因为可能有很多数字
        return l;
    }
    if (x>=k) ans=query(tree[tree1].l,tree[tree2].l,l,mid,k);//左节点最后一名在他后面就往左走，否则往右走。
    else ans = query(tree[tree1].r,tree[tree2].r,mid+1,r,k-x);
    return ans;
}
void Print(int root,int l,int r){
    cout<<"root:"<<root<<" l->"<<tree[root].l<<" r->"<<tree[root].r<<"   sum==="<<tree[root].sum<<"("<<l<<","<<r<<")"<<"\n";
    if (l==r) return;
    int mid=(l+r)/2;
    Print(tree[root].l,l,mid);
    Print(tree[root].r,mid+1,r);
}
int main(){
    cin>>n>>m;
    for (ll i=1;i<=n;i++) {cin>>a[i]; rk[i]=a[i];}
    sort(rk+1,rk+1+n);
    ll q = unique(rk+1,rk+1+n)-rk-1;
    build(++tree_cnt,1,q);//这种方式就类似于链式前向星，那样写主席树类似于建图之类的。

    //Print(1,1,q);
    rt[0]=1;//这边出过错，属于initialize
    for (ll i=1;i<=n;i++){
        p = lower_bound(rk+1,rk+1+q,a[i])-rk;//用lower_bound查询第k大
        rt[i]=modify(rt[i-1],1,q);
    }
    // for (int i=0;i<=5;i++)
    //     Print(rt[i],1,q);
    while (m--){
        ll l,r,k;
        cin>>l>>r>>k;
        ll p = query(rt[l-1],rt[r],1,q,k);
        cout<<rk[p]<<endl;
    }
    return 0;
}