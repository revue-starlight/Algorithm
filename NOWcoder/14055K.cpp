#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int to[N],vis[N];
int n;
queue <int> q;
vector <vector<int>> ans;
vector <vector<pair<int,int>>> output_tot;
bool find_ring(){
    ans.clear();
    int cnt = 0;
    for (int i=1;i<=n;i++) vis[i]=0;
    for (int i=1;i<=n;i++){
        if (vis[i]==0){
            q.push(i);
            vector<int> vec;
            while (!q.empty()){
                int u = q.front();
                q.pop();
                vis[u]=1;
                vec.push_back(u);
                if (!vis[to[u]]) q.push(to[u]);
            }
            if (vec.size()>1) cnt++;
            ans.push_back(vec);
        }
    }
    if (cnt==0) return 0;
    vector <pair<int,int>> output;
    for (auto &s:ans){
        int nn = s.size();
        if (nn==2){
            output.push_back({s[0],s[1]});
        } else
        for (int i=1;i<(nn+1)/2;i++){
            output.push_back({s[i],s[nn-i]});
        }
    }
    output_tot.push_back(output);
    for (auto pp:output){
        swap(to[pp.first],to[pp.second]);
    }
    return 1;
}

int main(){
    cin>>n;
    for (int i=1;i<=n;i++) cin>>to[i];
    int tot = 0;
    while (find_ring()){tot++;}
    cout<<output_tot.size()<<"\n";
    for (auto &output:output_tot){
        cout<<output.size()<<" ";
        for (auto pp:output){
            cout<<pp.first<<" "<<pp.second<<" ";
        }
        cout<<"\n";
    }
    return 0;
}