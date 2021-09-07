#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N = 3e5+100;
vector <pair<int,int>> vec[N];
int main(){
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        vec[a].push_back({b,c});
    }
    for (int i=1;i<=n;i++) sort(vec[i].begin(),vec[i].end());
    for (int i=1;i<=n;i++){
        
    }
    
}