#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
unordered_set <int> out[N];
struct Node{
    int sizee;
    int id;
    const bool operator < (const Node &rhs) const {
        if (sizee==rhs.sizee) return id>rhs.id;
        return sizee > rhs.sizee;
    }
};
int cnt;
priority_queue <Node> pq;
int sizee[N];
int lste[N];
int vis[N];
int T,TT;
void solve(){
    cnt++;
    int n;
    cin>>n;
    while (!pq.empty()) pq.pop();
    vector <int> ans;
    ans.resize(n+2);
    for (int i=1;i<=n;i++) {out[i].clear();sizee[i]=0;vis[i]=0;lste[i]=0;}
    for (int i=1;i<=n;i++){
        int p;
        cin>>p;
        for (int j=1;j<=p;j++){
            int too;
            cin>>too;
            out[too].insert(i);
        }
        sizee[i]=p; 
        if (p==0) ans[i]=1;
    }
    for (int i=1;i<=n;i++){
        pq.push({sizee[i],i});
    }
    int rett=-1;
    ans[0]=1;
    while (!pq.empty()){
        Node topper = pq.top();
        pq.pop();
        if (vis[topper.id]==1) continue;
        if (topper.sizee>0) {
            rett = -1;
            break;
        }
        vis[topper.id]=1;
        rett = max(ans[topper.id],rett);

        unordered_set<int>::iterator iter;
        for (iter=out[topper.id].begin();iter!=out[topper.id].end();iter++){
            int tmp = ans[topper.id];
            if ((*iter)<topper.id) tmp++;
            ans[(*iter)] = max(ans[(*iter)],tmp);
            rett = max(ans[*iter],rett);
            sizee[*(iter)]--;
            if (sizee[*(iter)]==0)
                pq.push({sizee[*(iter)],*(iter)});
        }
    }
    cout<<rett<<"\n";
}
int main(){
    cin>>T;
    TT = T;
    while (T--) solve();
}