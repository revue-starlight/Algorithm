#include <bits/stdc++.h>
using namespace std;
int a[51][51];
void solve(){
    int n;
    memset(a,0,sizeof(a));
    cin>>n;
    int wolf = -1;
    for (int i=1;i<=n;i++){
        int x;
        cin>>x;
        if (x==1) wolf = i;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    int killed = 1;
    int dead[51];
    int now = a[wolf][1];
    if (now==wolf){cout<<"lieren\n"; return;}
    memset(dead,0,sizeof(dead));
    dead[now]=1;
    while (1){
        if (dead[wolf]==true) {cout<<"lieren\n"; return;}
        if (n-killed<=2) {cout<<"langren\n"; return;}
        int p = 1;
        while (dead[a[now][p]]==1) p++;
        now = a[now][p];
        dead[now]=true;
        killed++;
    }
}
int main(){
    int T;
    cin>>T;
    while (T--) solve();
}