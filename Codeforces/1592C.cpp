#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+100;
int a[N];
struct edge{
    int u,v,next;
}e[N<<2];
int tot = 0,head[N];
int ppp= 0;
int cntt = 0;
void add(int u,int v){e[++tot]={u,v,head[u]}; head[u]=tot;}
int dfs(int u,int fa){
    for (int i=head[u];i;i=e[i].next){
        int v = e[i].v;
        if (v!=fa){
            if (dfs(v,u)!=0){
                a[u]^=a[v];
            }
        }
    }
    if (a[u]==ppp) {cntt++;return 0; }
    else return a[u];
}

void solve(){
    int n,m;
    cin>>n>>m;
    memset(head,0,sizeof(head));
    tot = 0;
    cntt = 0;
    ppp = 0;
    for (int i=1;i<=n;i++) cin>>a[i],ppp^=a[i];
    for (int i=1;i<=n-1;i++){
        int uu,vv;cin>>uu>>vv;
        add(uu,vv); add(vv,uu);
    }
    if (ppp == 0){ cout<<"yes\n"; return;}
    if (m==2) {cout<<"no\n"; return;}
    if (dfs(1,0)==0 && cntt>1) {
        cout<<"yes\n";
    } else {
        cout<<"no\n";
    }
}
int main(){
    int T;
    cin>>T;
    while (T--) solve();
}