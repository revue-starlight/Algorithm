#include <bits/stdc++.h>
using namespace std;
const int N = 2e2+10,M = 2e2+10;
const int MAXN = 2e7+100;
const int P = 1000;
int n,m,q;
int p[N][M];
int pre[N][M][1002];
int r1,c1,r2,c2,h;
int cnt[N][M][1002];
struct Node{
    int ls,rs,sum,cnt;
} tree[MAXN]; //权值线段树
int rt[MAXN],tcnt;



int add(int l,int r,int pre,int n){
    int pos = ++tcnt;
    tree[pos] = tree[pre];
    if (l==r){
        tree[pos].sum+=n;
        tree[pos].cnt+=1;
        return pos;
    }
    else {
        int mid=(l+r)>>1;
        if (n<=mid) tree[pos].ls = add(l,mid,tree[pre].ls,n);
        else tree[pos].rs = add(mid+1,r,tree[pos].rs,n);
        tree[pos].sum = tree[tree[pos].ls].sum+tree[tree[pos].rs].sum;
        tree[pos].cnt = tree[tree[pos].ls].cnt+tree[tree[pos].rs].cnt;
        return pos;
    }
}
int rem;
int check(int l,int r,int lft,int rht,int p){
    if (l==r){
        return (p-1)/l+1;
    }
    int mid = (l+r)/2;
    int rcnt = tree[tree[rht].rs].cnt-tree[tree[lft].rs].cnt;
    int rsum = tree[tree[rht].rs].sum-tree[tree[lft].rs].sum;
    if (p<=rsum) {
        return check(mid+1,r,tree[lft].rs,tree[rht].rs,p);
    }
    else {
        return check(l,mid,tree[lft].ls,tree[rht].ls,p-rsum)+rcnt;
    }
}


int check(int mid){
    int sum = pre[r2][c2][mid]-pre[r2][c1-1][mid]-pre[r1-1][c2][mid]+pre[r1-1][c1-1][mid];
    return sum;
}
int main(){
    cin>>n>>m>>q;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>p[i][j];
         }
    }

    if (n==1){
        for (int i=1;i<=m;i++) {
            rt[i]=add(1,P,rt[i-1],p[1][i]);
        }
        while (q--){
            cin>>r1>>c1>>r2>>c2>>h;
            if (tree[rt[c2]].sum-tree[rt[c1-1]].sum<h) {
                cout<<"Poor QLW\n";
                continue;
            }
            cout<<check(1,P,rt[c1-1],rt[c2],h)<<"\n";
            
        }
        return 0;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            for (int x=1000;x>=0;x--){
                if (p[i][j]!=x){
                    pre[i][j][x]=pre[i-1][j][x]+pre[i][j-1][x]-pre[i-1][j-1][x];
                    cnt[i][j][x]=cnt[i-1][j][x]+cnt[i][j-1][x]-cnt[i-1][j-1][x];
                }
                else {
                    pre[i][j][x]=pre[i-1][j][x]+pre[i][j-1][x]-pre[i-1][j-1][x]+p[i][j];
                    cnt[i][j][x]=cnt[i-1][j][x]+cnt[i][j-1][x]-cnt[i-1][j-1][x]+1;
                }
            }
        }
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            for (int x=1000;x>=0;x--){
                pre[i][j][x]+=pre[i][j][x+1];
                cnt[i][j][x]+=cnt[i][j][x+1];
            }
        }
    }
    
    while (q--){
        cin>>r1>>c1>>r2>>c2>>h;
        int l=0,r=1000;
        int last;
        while (l<r){
            int mid=(l+r+1)/2;
            if (check(mid)>=h) l=mid; else r=mid-1;
        }
        if (l==0 && check(0)<h) cout<<"Poor QLW\n";
            else{
                int delta = h-check(l+1);
                int delta2 = (delta+l-1)/l;
                cout<<cnt[r2][c2][l+1]-cnt[r1-1][c2][l+1]-cnt[r2][c1-1][l+1]+cnt[r1-1][c1-1][l+1]+delta2<<"\n";
            }
    }
    return 0;
}