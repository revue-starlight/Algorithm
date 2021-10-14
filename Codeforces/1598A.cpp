#include <bits/stdc++.h>
using namespace std;
int a[2][105];
int m;
int in_map(int u,int v){
    if (u<0 || u>2 || v<1 || v>m) return 0;
    return 1;
}
void dfs(int u,int v){
    a[u][v]=2;
    if (in_map(u+1,v) && a[u+1][v]==0){
        dfs(u+1,v);
    }
    if (in_map(u-1,v) && a[u-1][v]==0){
        dfs(u-1,v);
    }
    if (in_map(u,v+1) && a[u][v+1]==0){
        dfs(u,v+1);
    }
    if (in_map(u,v-1) && a[u][v-1]==0){
        dfs(u,v-1);
    }
    if (in_map(u+1,v+1) && a[u+1][v+1]==0){
        dfs(u+1,v+1);
    }
    if (in_map(u+1,v-1) && a[u+1][v-1]==0){
        dfs(u+1,v-1);
    }
    if (in_map(u-1,v-1) && a[u-1][v-1]==0){
        dfs(u-1,v-1);
    }
    if (in_map(u-1,v+1) && a[u-1][v+1]==0){
        dfs(u-1,v+1);
    }
}
int main(){
    int T;
    cin>>T;
    while (T--){
        string s,t;
        cin>>m;
        int n=m;
        cin>>s>>t;
        for (int i=0;i<=n+1;i++) a[0][i]=a[1][i]=0;
        for (int i=1;i<=n;i++){
            if (s[i-1]=='0') a[0][i]=0;
            else a[0][i]=1;
            if (t[i-1]=='0') a[1][i]=0;
            else a[1][i]=1;
        }
        dfs(0,1);
        if (a[1][n]==2) cout<<"Yes\n"; else cout<<"No\n";
    }
}