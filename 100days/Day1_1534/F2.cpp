#include <bits/stdc++.h>
using namespace std;
const int N = 4e5+10;
int n,m;
char ch[N],pres[N];
int cnt;
int nxt[N],tot,head[N];
struct E{
    int u,v,next;
}e[N*5];
vector <pair<int,int> > dp;
int a[N];
int dfn[N],low[N];
int vis[N];
int ind[N],r_ind[N];
int sta[N],index,insta[N];
int mp[N],key_id[N];
int getcol[N];
vector <int> revmp[N];
vector <int> G[N];
bool key_scc[N];
int ans = 0;
vector <int> col[N];
struct left_scc{
    int id,lft;
    bool operator<(const left_scc &b) const{return lft<b.lft;}
}Left_Scc[N];
struct range {
  int l, r;
  bool operator<(const range &r) const { return l < r.l; }
} ran[N];
void dfs(int u){
    vis[mp[u]]=1;
    int color = mp[u];
    for (int j = 0;j<revmp[color].size();j++){
        int u = revmp[color][j];
        for (int i=head[u];i;i=e[i].next){
            int v = e[i].v;
            if (vis[mp[v]]==0) dfs(v);
        }
    }
}
int dep;
int color;
int find_col(int ind){
    return getcol[ind];
}
void tarjan(int u){
    dep++;
    dfn[u]=low[u]=dep;
    sta[index++]=u;
    insta[u]=1;
    for (int i=head[u];i;i=e[i].next){
        int v = e[i].v;
        if (dfn[v]==0){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        if (insta[v]==1) low[u]=min(low[u],low[v]);
    }
    if (low[u]==dfn[u]){
        color++;
        Left_Scc[color].lft = numeric_limits<int>::max();
        while (sta[index]!=u){
            index--;
            mp[sta[index]]=color;
            Left_Scc[color]={color,min(find_col(sta[index]),Left_Scc[color].lft)};
            insta[sta[index]] = 0;
            revmp[color].push_back(u);
        }

    }
}

void add(int u,int v){
    if (u==-1) return;
    e[++tot]={u,v,head[u]}; head[u]=tot;
    return;
}

int key_cnt = 0;
void do_dp(){
    vector <int> ord;
    for (int i=1;i<=color;++i){
        if (!r_ind[i]) ord.push_back(i);
    }
    for (int i=0;i<color;++i){
        int x = ord[i];
        if (vis[x]) key_scc[x] = false;
        if (key_scc[x]) vis[x]=true;
        for (int v:G[x]){
            --r_ind[v];
            if (vis[x]||key_scc[x])  vis[v]=true;
            if (!r_ind[v]) ord.push_back(v);
        }
    }
    sort(Left_Scc+1,Left_Scc+color+1);
    for (int i=1;i<=color;i++){
        if (key_scc[Left_Scc[i].id]) key_id[Left_Scc[i].id] = ++key_cnt;
    }
    for (auto i = ord.rbegin();i!=ord.rend();i++){
        int x = *i;
        ran[x].l = key_scc[x]? key_id[x] : numeric_limits<int>::max();
        ran[x].r = key_scc[x]? key_id[x] : numeric_limits<int>::min();
        for (int v:G[x]){
            ran[x].l = min(ran[x].l,ran[v].l);
            ran[x].r = max(ran[x].r,ran[v].r);
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    memset(nxt,-1,sizeof(nxt));
    for (int i=1;i<=n;i++){
        scanf("%s",ch+1);
        for (int j=1;j<=m;j++){
            if (ch[j]=='#'){
                cnt++;
                add(nxt[j],cnt);
                add(nxt[j-1],cnt);
                if (pres[j]=='#')
                    add(cnt,nxt[j]);
                if (ch[j+1]=='#') add(cnt+1,cnt);
                else add(nxt[j+1],cnt);
                nxt[j]=cnt;
                getcol[cnt]=j;
                col[j].push_back(cnt);
            }
        }
        for (int i=1;i<=m;i++) pres[i]=ch[i];
    }
    for (int i=1;i<=m;i++){cin>>a[i];}
    // Tarjan 缩点
    // int ans = 0;
    for (int i=1;i<=cnt;i++)
        if (low[i]==0){
            tarjan(i);
        }
    int ans=0;
    
    for (int i=1;i<=tot;i++){
       int u = e[i].u, v = e[i].v;
       if (mp[u]!=mp[v]) G[mp[u]].push_back(mp[v]),r_ind[mp[v]]++;
    }

    for (int i=1;i<=m;i++){
        if (a[i]!=0){
            key_scc[mp[col[i][col[i].size()-a[i]]]]=true;
        }
    }
    memset(vis,0,sizeof(vis));
    do_dp();
    sort(ran+1, ran + color+1);
    int max_r = 0, nmax_r = 0, res = 0;
    for (int i = 1; i <= color && max_r < key_cnt; ++i) {
    nmax_r = max(nmax_r, ran[i].r);
    if (i == color || ran[i + 1].l > max_r + 1)
      ++res, max_r = nmax_r;
  }
  printf("%d\n", res);
    return 0;
}