#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("make.in","w",stdout);
    int n,m;
    srand(time(NULL));
    n = rand()%9+1;
    m = rand()%n+1;
    cout<<n<<" "<<m<<"\n";
    int vis[n+1];
    memset(vis,0,sizeof(vis));
    for (int i=1;i<=m;i++){
        int p;
        do {
            p = rand()%n+1;
        } while (vis[p]!=0);
        vis[p]=1;
        int q = rand()%p+1;
        cout<<p<<" "<<q<<"\n";
    }
    return 0;
}