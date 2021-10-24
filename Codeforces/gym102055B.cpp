#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+100;

struct Seg{
    int a[2],id;
    bool operator < (const Seg &rhs) const {
        if (a[1]==rhs.a[1]) return a[0]<rhs.a[0];
        return a[1]<rhs.a[1];
    }
};

int T;
int cas = 0;
bool boo = false;
vector <Seg> segs;
struct Tree{
    int l,r,val;
}t[N<<2];
const int INITIAL = numeric_limits<int>::max();
int a[N][2];
int head[N],tot;
struct Edge{
    int u,v,next;
}e[N<<1];
int sc[N],vis[N];
Seg tmp[2];


void print(){
    cout<<"Case "<<++cas<<": ";
}

void add(int u,int v){e[++tot]={u,v,head[u]};head[u]=tot;}
void dfs(int u,int fa){
    sc[u]=sc[fa]^1;
    tmp[sc[u]].a[0]=min(tmp[sc[u]].a[0],a[u][0]);
    tmp[sc[u]].a[1]=max(tmp[sc[u]].a[1],a[u][0]);
    tmp[sc[u]^1].a[0]=min(tmp[sc[u]^1].a[0],a[u][1]);
    tmp[sc[u]^1].a[1]=max(tmp[sc[u]^1].a[1],a[u][1]);
    vis[u]=1;
    for (int i=head[u];i;i=e[i].next){
        int v = e[i].v;
        if (vis[v] && v!=fa && sc[u]==sc[v]){
            boo = false;
            return;
        }
        if (!vis[v]) dfs(v,u);
    }
}

void build(int x,int l,int r){
    t[x]={l,r,0};
    if (l==r) {
        t[x].val = numeric_limits<int>::max();
        return;
    }
    int mid = (l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    t[x].val = min(t[x<<1].val,t[x<<1|1].val);
}


void update(int x,int l,int r,int TO,int val){
    if (l==r) {
        t[x].val = val;
        return;
    } else {
        int mid = (l+r)>>1;
        if (TO<=mid){
            update(x<<1,l,mid,TO,val);
        }
        else update(x<<1|1,mid+1,r,TO,val);
        t[x].val = min(t[x<<1].val,t[x<<1|1].val);
    }
}

int query(int x,int l,int r,int L,int R){
    if (L<=l && r<=R) {
        return t[x].val;
    } else {
        int minn = numeric_limits<int>::max();
        int mid = (l+r)>>1;
        if (L<=mid) minn = query(x<<1,l,mid,L,R);
        if (R>mid) minn = min(query(x<<1|1,mid+1,r,L,R),minn);
        return minn;
    }
}


void solve(){
    segs.clear();
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++) vis[i]=0;
    for (int i=1;i<=n;i++) head[i]=0;
    tot = 0;
    for (int i=1;i<=m;i++){
        int uu,vv;
        cin>>uu>>vv;
        add(uu,vv); add(vv,uu);
    }
    for (int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1];
    }
    int sz = 0;
    for (int i=1;i<=n;i++){
        if (!vis[i]) {
            sz++;
            tmp[0]=tmp[1] = {{numeric_limits<int>::max(),0},sz};
            boo = true;
            dfs(i,0);
            if (!boo){
                print(); cout<<"IMPOSSIBLE\n";
                return;
            }
            segs.push_back(tmp[0]);
            segs.push_back(tmp[1]);
        }
    }


    sort(segs.begin(),segs.end());
    build(1,1,sz);
    int ans = numeric_limits<int>::max();
    for (int i=1;i<=sz;i++) vis[i]=0;
    int sum = 0;
    for (auto seg:segs){
        if (vis[seg.id]==0) {
            vis[seg.id]=1;
            sum++;
        }
        int tmp = query(1,1,sz,seg.id,seg.id);
        if (sum == sz){
            update(1,1,sz,seg.id,seg.a[0]);
            ans = min(ans,seg.a[1]-t[1].val);
        }
        if (tmp == numeric_limits<int>::max()) tmp = 0;
        update(1,1,sz,seg.id,max(seg.a[0],tmp));
    }
    print(); cout<<ans<<"\n";
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--)solve();
}