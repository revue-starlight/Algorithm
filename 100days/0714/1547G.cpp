#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+10;
struct Node{
    int u,v,next;
}e[N<<1];
int tot,head[N];
int n,m;
stack <int> tar;
int instack[N];
int dep[N],vis[N],low[N],dfn[N],cnt,ans[N];
int belongto[N];
int colornum;
vector <vector<int> > newmp;
int T;
void add(int u,int v){
    e[++tot]={u,v,head[u]}; head[u]=tot;
}
void tarjan(int u){
    low[u]=dfn[u]=++cnt;
    instack[u]=1;tar.push(u);
    for (int i=head[u];i;i=e[i].next){
        int v = e[i].v;
        if (!dfn[v]){
            tarjan(v); 
            low[u]=min(low[v],low[u]);
        }else{
            if (instack[v] && dfn[v]<low[u])
                low[u]=dfn[v];
        }
    }
    if (low[u]==dfn[u]){
        vector <int> vec;
        colornum++;
        while (tar.top()!=u){
            int u = tar.top();
            tar.pop();
            belongto[u]=colornum;
            instack[u]=0;
            vec.push_back(u);
        }
        u = tar.top();
        belongto[u]=colornum;
        instack[u]=0;
        vec.push_back(u);
        tar.pop();
        newmp.push_back(vec);
    }
}
int ppp=0;
unordered_set <int> s;
void solve(){
    //memset(instack,0,sizeof(instack));
    //memset(head,0,sizeof(head));
    tot=0;
    //memset(dfn,0,sizeof(dfn));
    //memset(ans,0,sizeof(ans));
    newmp.clear();
    s.clear();
    colornum=0;
    cnt = 0;    
    cin>>n>>m;
    for (int i=0;i<=n+m;i++){
        instack[i]=head[i]=dfn[i]=ans[i]=0;
    }
    ans[1]=1;
    for (int i=1;i<=m;i++){
        int u,v; cin>>u>>v; add(u,v);
        // if (ppp==61){
        //     cout<<"----";
        //     cout<<u<<" "<<v<<endl;
        // }
        if (u==v) s.insert(u);
        // if (u==v) ans[u]=-1;
    }
    tarjan(1);
    reverse(newmp.begin(),newmp.end());
    for (int i=0;i<colornum;i++){
        if (newmp[i].size()>1){
            for (auto s : newmp[i]){
                ans[s]=-1;
            }
        }
    }
    if (s.find(1)!=s.end()) ans[1]=-1;
    for (int i=0;i<colornum;i++){
        for (auto u: newmp[i]){
            for (int i=head[u];i;i=e[i].next){
                int v = e[i].v;
                if (s.find(v)!=s.end()) ans[v]=-1;
                if (ans[v]==-1) continue;
                if (ans[u]==-1) ans[v]=-1;
                if (ans[u]==2){
                    if (ans[v]!=2) ans[v]=2;
                }
                if (ans[u]==1){
                    if (ans[v]==1) ans[v]=2;
                    if (ans[v]==0) ans[v]=1;
                }
            }
        }
    }
    for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;
}
signed main(){
    cin>>T;
    while (T--) {
        ppp++;
        solve();
    }
}