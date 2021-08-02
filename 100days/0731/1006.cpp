#include <bits/stdc++.h>
using namespace std;
const int N = 5e6+10;
int n,m,k;
int a[N],nxt[N],pre[N];
void solve(){
    // freopen("data.in","r",stdin);
    // freopen("data2.out","w",stdout);
    scanf("%d",&n);
    m=n+1;
    int ans = 0;
    int p = 1;
    for (int i=1;i<=n;i++) nxt[i]=i+1,pre[i]=i-1;
    for (int i=1;i<=n;i++){
        int typ,x;
        scanf("%d%d",&typ,&x);
        if (typ == 1){
            if (a[x]==1) continue;
            a[x]=1;
            nxt[pre[x]]=nxt[x];
            pre[nxt[x]]=pre[x];
            while (a[p]==1) p++;
        } 
        else {
            if (x==p) printf("%d\n",nxt[p]);
            else printf("%d\n",p);
        }
    }
}
signed main(){
    solve();
}
/*
10
2 3
2 2
2 1
1 1
2 2
2 3
1 3
2 2
*/