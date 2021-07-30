#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
struct E{
    int u,v,next;
}e[N<<1];
int tot,head[N];
int dep[N];
int f[N][20];
void add(int u,int v){e[++tot]={u,v,head[u]};head[u]=tot;}
void getdep(int u,int fa){
    dep[u]=dep[fa]+1;
    f[u][0]=fa;
    for (int i=1;i<20;i++) f[u][i]=f[f[u][i-1]][i-1];
    for (int i=head[u];i;i=e[i].next){
        if (e[i].v!=fa)
            getdep(e[i].v,u);
    }
}
int n,m,s;
int main(){
    cin>>n>>m>>s;
    for (int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        add(x,y); add(y,x);
    }
    int root = s;
    getdep(root,0);
    while (m--){
        int u,v;
        cin>>u>>v;
        if (dep[u]<dep[v])swap(u,v);
        for (int i=19;i>=0;i--)
            if (dep[u]-(1<<i)>=dep[v]) u=f[u][i];
        swap(u,v);
        if (u==v) cout<<v<<endl; 
        else{
            for (int i=19;i>=0;i--){
                if (f[u][i]!=f[v][i]){
                    u=f[u][i];
                    v=f[v][i];
                }
            }
            cout<<f[u][0]<<endl;
        }
    }
    return 0;
}