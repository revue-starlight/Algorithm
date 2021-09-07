#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+100;
const int M = 1e3+100;
struct E{
    int u,v;
    const bool operator < (const E &b) const{
        if (v==b.v) return u>b.u;
        else return v>b.v;
    }
}flight[N];
int to[N];
int n,m;
double ans[N];
int main(){
    while (~scanf("%d%d",&n,&m)){
        if (n==0) break;
        for (int i=0;i<=n+6;i++) ans[i]=0;
        for (int i=1;i<=m;i++) scanf("%d%d",&flight[i].u,&flight[i].v);
        sort(flight+1,flight+1+m);
        for (int i=0;i<=n+6;i++) to[i]=i;
        for (int i=1;i<=m;i++){
            to[flight[i].u]=to[flight[i].v];
        }
        for (int i=n-1;i>=0;i--){
            if (to[i]!=i){ ans[i]=ans[to[i]];continue;}
            double now = 0;
            for (int q = 1 ;q<=6;q++){
                now+=ans[to[q+i]];
            }
            ans[i]=now/6+1;
        }
        printf("%.4lf\n",ans[0]);
    }
    return 0;

    
}