#include <bits/stdc++.h>
using namespace std;
int T;
const int N = 1e5+100;
int a[N];
void solve(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    memset(a,0x3f,sizeof(a));
    a[k]=0;
    for (int i=1;i<=m;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        int uu = min(a[v],a[u]+1);
        int vv = min(a[u],a[v]+1);
        a[u]=uu;
        a[v]=vv;
    }
    for (int i=1;i<n;i++){
        if (a[i]>1e5+10) printf("-1 ");
        else printf("%d ",a[i]);
    }
    if (a[n]>1e5+10) printf("-1");
    else printf("%d",a[n]);
    printf("\n");
    return;
}
int main(){
    scanf("%d",&T);
    while (T--) solve();
}