#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+100;
int head[N],tot;
struct Edge{
    int u,v,next;
}e[N<<2];
int n;
int val[N];
void add(int u,int v){e[++tot]={u,v,head[u]}; head[u]=tot;}
int rnk[N],ans[N];
bool cmp(int u,int v){
    return val[u]<val[v];
}
vector <int> vec;
vector <int> entrance;
void dfs(int u,int fa){
    vec.push_back(u);
    for (int i=head[u];i;i=e[i].next){
        int v = e[i].v;
        if (e[i].v!=fa && val[e[i].v]>val[e[i].u]){
            if (ans[v]==-1)
                dfs(v,u);
            else entrance.push_back(v);
        }
    }
}
void solve(){
        cin>>n;
        for (int i=1;i<=n;i++) head[i]=0;
        tot = 0;
        for (int i=1;i<=n;i++) {ans[i]=-1;}
        for (int i=1;i<n;i++){
            int uu,vv;
            cin>>uu>>vv;
            add(uu,vv); add(vv,uu);
        }
        for (int i=1;i<=n;i++) cin>>val[i],rnk[i]=i;
        sort(rnk+1,rnk+1+n,cmp);
        for (int i=1;i<=n;i++){
            if (ans[rnk[i]]==-1){
                vec.clear(); entrance.clear();
                dfs(rnk[i],0);
                sort(vec.begin(),vec.end(),cmp);
                int num = vec.size();
                sort(entrance.begin(),entrance.end(),cmp);
                int aa[entrance.size()+1];// entrance 的值
                int bb[entrance.size()+1];// entrance 值的前缀和
                aa[0]=bb[0]=0;
                for (int i=0;i<entrance.size();i++){
                    aa[i+1]=val[entrance[i]];
                    bb[i+1]=aa[i+1]+bb[i];
                }
                int entrance_tot = entrance.size();
                for (auto pos: vec){
                    ans[pos]=num;
                    int pos_to_add = upper_bound(aa+1,aa+1+entrance_tot,val[pos])-1-aa;
                    if (pos_to_add>0)
                        ans[pos]+=bb[pos_to_add-1];
                    num--;
                }
            }
        }
        for (int i=1;i<=n;i++) cout<<ans[i]<<"\n";
}

signed main(){
    int T;
    cin>>T;
    while (T--){
        solve();
    }
}

/*
1
5
1 2
1 3
2 4
2 5
1 4 2 5 3


1
11
1 10
1 2
10 9
10 6
2 7
6 3
6 5
5 4
5 8
8 11
1 2 3 4 5 6 7 8 9 10 11
*/