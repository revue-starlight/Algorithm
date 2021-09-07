#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
const int N = 1e5+100;
int rnk[N],id[10000003];
int q[N][2];
int t[N<<2];

void update(int x,int l,int r,int L,int R,int val){
    if (t[x]==-1){
        t[x]=0;
        t[x<<1]=t[x<<1|1]=-1;
    }
    if (L<=l && r<=R) {
        t[x]=val;
        return;
    }
    int mid = (l+r)/2;
    if (t[x]!=0){
        t[x<<1]=t[x<<1|1]=t[x];
        t[x]=0;
    }
    if (L<=mid) update(x<<1,l,mid,L,R,val);
    if (R>mid) update(x<<1|1,mid+1,r,L,R,val);
}
set<int> s;
void check(int x,int l,int r){
    if (t[x]!=0) {s.insert(t[x]); return;}
    if (t[x]==0){
        int mid = (l+r)/2;
        check(x<<1,l,mid);
        check(x<<1|1,mid+1,r);
    }
}
void solve(){
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d%d",&q[i][0],&q[i][1]);
        rnk[i*2-1]=q[i][0];
        rnk[i*2]=q[i][1];
    }
    sort(rnk+1,rnk+1+2*n);
    int lastpos = unique(rnk+1,rnk+1+2*n)-rnk;
    lastpos--;
    for (int i=1;i<=lastpos;i++){
        id[rnk[i]]=i;
    }
    s.clear();t[1]=-1;
    for (int i=1;i<=n;i++){
        int l = id[q[i][0]],r = id[q[i][1]];
        update(1,1,lastpos,l,r,i);
    }
    check(1,1,lastpos);
    if (s.find(-1)!=s.end()) s.erase(-1);
    printf("%d\n",s.size());
}
int main(){
    int T;
    scanf("%d",&T);
    while (T--) solve();
}