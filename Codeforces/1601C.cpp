#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+10;
struct NODE{
    int pos,x;
    const bool operator < (const NODE &B )const  {
        return x<B.x;
    }
    const bool operator > (const NODE &B )const  {
        return x>B.x;
    }
};

struct TREE{
    int l,r,lz;
    NODE x;
    const bool operator < (const TREE &B ) const {
        return x<B.x;
    }

    const bool operator > (const TREE &B ) const {
        return x>B.x;
    }
}tree[N<<3];
int T;
int a[N],b[N],c[N];
int id[N];
int n,m;


void build(int x,int l,int r){
    tree[x].l = l; tree[x].r = r; tree[x].lz = 0;
    if (l==r) tree[x].x = {l,-l+1};
    else {
        int mid = (l+r)>>1;
        build(x<<1,l,mid);
        build(x<<1|1,mid+1,r);
        tree[x].x = max(tree[x<<1].x,tree[x<<1|1].x);
    }
}


void pushdown(int x){
    if (tree[x].lz == 0){
        return;    
    }
    tree[x<<1].x.x += tree[x].lz;
    tree[x<<1|1].x.x += tree[x].lz;

    tree[x<<1].lz += tree[x].lz;
    tree[x<<1|1].lz += tree[x].lz;

    tree[x].lz = 0;
}
NODE query(int x,int l,int r,int L,int R){
    if (tree[x].lz!=0) pushdown(x);
    if (L<=l && r<=R) return tree[x].x;
    else {
        int mid = (l+r)>>1;
        NODE ret , ret2;
        ret = {-1,-1};
        ret2 = ret;
        if (L<=mid) 
            ret = query(x<<1,l,mid,L,R);
        if (R>mid)
            ret2 = query(x<<1|1,mid+1,r,L,R);
        return max(ret,ret2);
    }
}

void upd(int x,int l,int r,int L,int R,int v){
    pushdown(x);
    if (L<=l && r<=R){
        tree[x].x.x += v;
        tree[x].lz += v;
        return;
    } 
    int mid = (l+r)>>1;
    if (L<=mid) upd(x<<1,l,mid,L,R,v);
    if (R>mid) upd(x<<1|1,mid+1,r,L,R,v);
    tree[x].x = max(tree[x<<1].x,tree[x<<1|1].x);
}

bool cmp(int x,int y){
    if (a[x]==a[y]) return x<y;
    return (a[x]<a[y]);
}


int ms(int l,int r){
    int ret = 0;
    if (l==r) return 0;
    int mid = (l+r)>>1;
    ret += ms(l,mid); ret+=ms(mid+1,r);
    vector <int> tmp;
    int rp = mid+1;
    for (int i=l;i<=mid;i++){
        while (rp<=r && c[rp]<c[i]) {ret += (mid-i+1); tmp.push_back(c[rp++]);}
        tmp.push_back(c[i]);
    }
    for (int i=rp;i<=r;i++) tmp.push_back(c[i]);

    for (int i=l;i<=r;i++) c[i] = tmp[i-l];
    return ret;
}


void solve(){
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];        
        id[i] = i;
    }
    for (int i=1;i<=m;i++) cin>>b[i]; sort(b+1,b+1+m); sort(id+1,id+1+n,cmp);
    build(1,1,n+1);
    int now = 1;
    int newinsert = 1;
    vector <NODE> ans;
    for (int i=1;i<=m;i++){
        while (a[id[now]]<b[i] && now<=n) 
            {upd(1,1,n+1,id[now]+1,n+1,2); now++;}
        NODE tmp;
        tmp = query(1,1,n+1,newinsert,n+1);
        ans.push_back(tmp);
        newinsert = tmp.pos;
    }
    
    now = 1;
    int b_pos = 0;
    for (int i=1;i<=n;i++){
        while (ans[b_pos].pos<=i) 
            {c[now++]=b[b_pos+1]; b_pos++;}
        c[now++] = a[id[i]];
    }
    for (int i=b_pos;i<m;i++){
        c[now++]=b[i+1];
    }
    now--;
    n = now;
    int ANS = 0;
    ANS += ms(1,n);
    cout<<ANS<<endl;
    return;
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--)solve();
}