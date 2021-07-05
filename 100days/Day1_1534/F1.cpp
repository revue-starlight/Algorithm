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
int dfn[N],low[N];
int vis[N];
int ind[N];
int sta[N],index,insta[N];
int mp[N];
vector <int> revmp[N];
int ans = 0;
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
        while (sta[index]!=u){
            index--;
            mp[sta[index]]=color;
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
            }
        }
        for (int i=1;i<=m;i++) pres[i]=ch[i];
    }
    for (int i=1;i<=m;i++){int x; cin>>x;}
    // Tarjan 缩点
    // int ans = 0;
    for (int i=1;i<=cnt;i++)
        if (low[i]==0){
            tarjan(i);
        }
    int ans=0;
    for (int i=1;i<=tot;i++){
        int u=e[i].u;
        int v=e[i].v;
        if (mp[u]!=mp[v]) ind[mp[v]]++;
    }
    for (int i=1;i<=color;i++){
        if (ind[i]==0) ans++;
    }
    printf("%d",ans);
    return 0;
}