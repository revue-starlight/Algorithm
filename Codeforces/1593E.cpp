#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 4e5+100;
int T;
int head[N],tot;
struct Edge{
    int u,v,next;
}e[N<<2];
int sumDeg[N<<2],vis[N];
void add(int u,int v){e[++tot]={u,v,head[u]};head[u]=tot;}
void solve(){
    int n,k;
    cin>>n>>k;
    if (n==1){
        cout<<"0\n";
        return;
    }
    for (int i=1;i<=n;i++) head[i]=0;
    tot = 0;
    for (int i=1;i<=n;i++) sumDeg[i]=0;
    for (int i=1;i<=n;i++) vis[i]=0;
    for (int i=1;i<n;i++){
        int uu,vv;
        cin>>uu>>vv;
        sumDeg[uu]++; sumDeg[vv]++;
        add(uu,vv); add(vv,uu);
    }
    queue <int> q;
    for (int i=1;i<=n;i++){
        if (sumDeg[i]==1)
            q.push(i);
    }
    int cnt = 0;
    stack <int> st;
    for (int i=1;i<=k;i++){
        while (!q.empty()){
            int u = q.front(); q.pop();
            vis[u]=1; cnt++;
            for (int i=head[u];i;i=e[i].next){
                int v = e[i].v;
                if (!vis[v]){
                    sumDeg[v]--;
                    if (sumDeg[v]==1){
                        st.push(v);
                    }
                }
            }    
        }
        while (!st.empty()){
            q.push(st.top()); 
            st.pop();
        }
    }
    cout<<n-cnt<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--)solve();
}