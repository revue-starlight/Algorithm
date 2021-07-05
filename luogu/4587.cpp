#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e5+100;
struct Node{
    int sum,l,r;
}tree[N<<5];
int a[N],tree_cnt,rt[N];
int add(int preroot,int l,int r,int p){// dynamic add point
    int pos=++tree_cnt;
    tree[pos]=tree[preroot];
    if (l==r) {
        tree[pos].sum+=l;
        return pos;
    }
    int mid = ((l+r)>>1);
    if (p<=mid)
        tree[pos].l=add(tree[preroot].l,l,mid,p);
    else
        tree[pos].r=add(tree[preroot].r,mid+1,r,p);
    tree[pos].sum=tree[tree[pos].l].sum+tree[tree[pos].r].sum;
    return pos;
}

int query(int root1,int root2,int l,int r,int tl,int tr){
    if (l>tr || r<tl) return 0;
    if (tl<=l && r<=tr) return tree[root2].sum-tree[root1].sum;
    else {
        int ret=0;
        int mid=(l+r)>>1;
        ret+=query(tree[root1].l,tree[root2].l,l,mid,tl,tr);
        ret+=query(tree[root1].r,tree[root2].r,mid+1,r,tl,tr);
        return ret;
    }
}

int main(){
    
    //freopen("C:\\Users\\19606\\Documents\\desktop\\desktop\\luogu\\test.in","r",stdin);
    //freopen("C:\\Users\\19606\\Documents\\desktop\\desktop\\luogu\\test1.out","w",stdout);
    
    const int A = 1e9+7;
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        rt[i]=add(rt[i-1],1,A,a[i]);
    }
    int m;
    cin>>m;
    while (m--){
        int l,r;
        cin>>l>>r;
        int lst=0,now=0,tmp;
        int ans=0;
        while (1){
            tmp = query(rt[l-1],rt[r],1,A,lst+1,now+1);
            if (tmp) {lst = now+1, now+=tmp;}
            else break;
        }
        cout<<now+1<<endl;
    }
    return 0;
}