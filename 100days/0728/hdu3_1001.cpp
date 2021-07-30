#include <iostream>
using namespace std;
const int N =  1e5+100;
struct NODE{
    int son,fa,siz,dep;
}t[N];
int top[N],dfn[N],rank[N];
const int inf = ~0U>>1;
int head[N],tot;
struct E{
    int u,v,next;
}e[N<<2];
void add(int u,int v){e[++tot]={u,v,head[u]};head[u]=tot;}
int n,m;
int dfncnt;
int val[N];
int V[N],vcnt;
int ga[N],gb[N],rga[N],rgb[N],nxt[N];
void ADD(int &x,int i){V[++vcnt]=i; nxt[vcnt]=x; x=vcnt;}
struct QUERY{
    int u,v,w;
}q[N];
void dfs(int u,int fa){
    t[u].siz=1;
    t[u].dep=t[fa].dep+1;
    t[u].fa = fa;
    int maxx = -1;
    for (int i=head[u];i;i=e[i].next){
        int v = e[i].v;
        if (v!=fa){
            dfs(v,u);
            t[u].siz+=t[v].siz;
            if (t[u].siz>maxx){maxx=t[u].siz;t[u].son=v;}
        }
    }
}

void dfs2(int x,int y){
    top[x]=y;
    dfn[x]=++dfncnt;
    rank[dfncnt]=x;
    if (t[x].son!=0) dfs2(t[x].son,y);
    for (int i=head[x];i;i=e[i].next){
        int v=e[i].v;
        if (v!=t[x].fa && v!=t[x].son) dfs2(v,v);
    }
}

inline void put(int x,int y,int id){
    while (top[x]!=top[y]){
        if (t[x].dep>t[y].dep){
            ADD(ga[dfn[x]],id);
            ADD(gb[dfn[top[x]]],id);
            x = t[top[x]].fa;
        }else{
            ADD(rga[dfn[top[y]]],id);
            ADD(rgb[dfn[y]],id);
            y=t[top[y]].fa;
        }
    }
    if (t[x].dep>t[y].dep){
        ADD(ga[dfn[x]],id);
        ADD(gb[dfn[y]],id);
    }else {
        ADD(rga[dfn[x]],id);
        ADD(rgb[dfn[x]],id);
    }
}

namespace DS{
    int a[N],val[N],tag[N],son[N][2],f[N],root;
    inline void add1(int x,int p){
        if (!x) return;
        val[x]+=p;
        tag[x]+=p;
    }
    inline void pb(int x){
        if (tag[x]){
            add1(son[x][0],tag[x]);
            add1(son[x][1],tag[x]);
            tag[x]=0;
        }
    }
    inline void rotate(int x){
        int y=f[x],w=son[y][1]==x;  
        son[y][w]=son[x][w^1];
        if (son[x][w^1]) f[son[x][w^1]]=y;
        if (f[y]){
            int z = f[y];
            if (son[z][0]==y) son[z][0]=x;
            if (son[z][1]==y) son[z][1]=x;
        }
        f[x]=f[y]; son[x][w^1]=y; f[y]=x;
    }
    inline void splay(int x,int w){
        int s=1,i=x,y;
        a[1]=x;
        while (f[i]) a[++s]=i=f[i];
        while (s) pb(a[s--]);
        while (f[x]!=w){
            y=f[x];
            if (f[y]!=w){
                if((son[f[y]][0]==y)^(son[y][0]==x))rotate(x);else rotate(y);
            }
            rotate(x);
        }
        if (!w) root = x;
    }
    inline void ask(int k){// find 1st element >=k
        int y = root,t;
        while (y!=0){
            if (val[y]>=k){
                t = y;
                y = son[y][0];
            } else {
                y = son[y][1];
            }
        }
        splay(t,0);
    }
    inline void ins(int x){
        int now = root;
        son[x][0]=son[x][1]=f[x]=tag[x]=0;
        while (1){
            int w = val[now]>x;
            if (!son[now][w]){
                son[now][w]=x;
                f[x]=now;
                break;
            }
            now = son[now][w];
        }
        splay(now,0);
    }
    inline void change(int k){
        while (1){
            ask(k);
            int x=root;
            if (val[x]<k*2){
                int y = son[x][1];
                while (son[y][0]) y=son[y][0];
                splay(y,x);
                son[y][0]=son[x][0];
                f[y]=0;
                f[son[x][0]]=y;
                root=y;
                val[x]-=k;
                ins(x);
            } else {
                val[x]-=k;
                add1(son[x][1],-k);
                while (son[x][1]) x = son[x][1];
                splay(x,0);
                val[x]=inf;
                return;
            }
        }
        
    }
    inline void init(){
        for (int i=m+1;i<=m+2;i++) son[i][0]=son[i][1]=f[i]=tag[i]=0;
        val[m+1]=-1;
        val[m+2]=inf;
        root=m+1;
        son[m+1][1]=m+2;
        f[m+2]=m+1;
    }
    inline void Del(int x){
        splay(x,0);
        q[x].w=val[x];
        int A=son[x][0],B=son[x][1];
        f[A]=f[B]=0;
        while (son[A][1]) A=son[A][1];
        splay(A,0);
        son[A][1]=B;
        f[B]=A;
    }
}

void solve(){
    dfncnt=0;
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>val[i];
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        add(u,v);add(v,u);
    }
    for (int i=1;i<=m;i++){
        cin>>q[i].u>>q[i].v>>q[i].w;
    }
    dfs(1,0);
    dfs2(1,0);
    for (int i=1;i<=m;i++){
        put(q[i].u,q[i].v,i);
    }
}


int main(){
    int T;
    cin>>T;
    while (T--) solve();
}