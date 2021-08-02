#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;
int a[1011];
int fa[1011];
int vis[1011];
int blackpoint,unionnum;
int getfa(int x){return x == fa[x] ? x : fa[x] = getfa(fa[x]);}
void solve(){
    int n,s;
    cin>>n>>s;
    if (n==1) {cout<<0<<"\n"; return;}
    int cnt = 0;
    blackpoint = 0;
    unionnum = 0;
    for (int i=1;i<=n;i++) a[i]=0;
    for (int i=1;i<=n;i++) fa[i]=i;
    for (int i=1;i<=n;i++) vis[i]=0;
    for (int v=2;v<=n;v++){
        string s;
        cin>>s;
        for (int j=0;j<s.length();j++){
            int u = j+1;
            if (s[j]=='0'){
                if (vis[u]==0) {
                    vis[u]=1;
                    blackpoint++;
                }
                if (vis[v]==0){
                    vis[v]=1;
                    blackpoint++;
                }
                cnt++;
                a[u]++;
                a[v]++;
                int x = getfa(u);
                int y = getfa(v);
                if (x!=y)
                    unionnum++,fa[x]=y;
            }
        }
    }
    int ans = 0;
    for (int i=1;i<=n;i++){
        if (a[i]%2!=0) ans++;
    }
    if (ans==0 || (ans==2 && a[s]%2!=0)) {
        int res = cnt+(blackpoint-unionnum-1)*2;
        if (ans==0 && vis[s]==0) res+=2;
        res = max(res,0ll);
        cout<<res<<"\n";
    } else {
        cout<<"-1\n";
    }
}
signed main(){
    // freopen("data.in","r",stdin);
    // freopen("test.out","w",stdout);
    cin>>T;
    while (T--) solve();
}