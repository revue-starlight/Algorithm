#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5+10;
pair<pair <int,int>,int> a[N];
struct RECORD{
    int r,id;
    const bool operator < (const RECORD &rhs) const{
        return r>rhs.r;
    }
};
priority_queue <RECORD> pq;
struct E{
    int u,v,next;
}e[N<<2];
int head[N],tot;
void add(int u,int v){e[++tot]={u,v,head[u]}; head[u]=tot;}
int sum[N];
set <int> s;
int dp[N];
int pre[N];
int n,m;
signed main(){
    cin>>n>>m;
    for (int i=1;i<=m;i++) cin>>a[i].second>>a[i].first.first>>a[i].first.second;
    sort(a+1,a+1+m);
    s.insert(0);
    s.insert(n+1);
    for (int i=1;i<=m;i++){
        pq.push({a[i].first.second,a[i].second});
        sum[a[i].second]++;
        s.insert(a[i].second);
        while (!pq.empty() && pq.top().r<a[i].first.first){
            sum[pq.top().id]--; 
            if (sum[pq.top().id]==0)
                s.erase(pq.top().id);
            pq.pop();
        }
            
            set<int>::iterator ss;
            ss = s.find(a[i].second);
            ss--;
            int v1 = *(ss);
            ss++;
            ss++;
            int v2 = *(ss);
            add(a[i].second,v1);add(a[i].second,v2);
            add(v1,a[i].second);add(v2,a[i].second);
    }
    
    for (int node=1;node<=n+1;node++){
        for (int i=head[node];i;i=e[i].next){
            if (e[i].v<node) 
                if (dp[e[i].v]+1>dp[node]){
                    dp[node]=dp[e[i].v]+1;
                    pre[node]=e[i].v;
                }
        }
    }

    int now = n+1;
    vector <int> ans;
    while (now!=0){
        ans.push_back(now);
        now = pre[now];
    }
    ans.push_back(0);
    reverse(ans.begin(),ans.end());
    cout<<n-(ans.size()-2)<<"\n";
    for (int i=1;i<ans.size();i++){
        for (int j=ans[i-1]+1;j<ans[i];j++){
            cout<<j<<" ";
        }
    }
    cout<<"\n";
    return 0;
}