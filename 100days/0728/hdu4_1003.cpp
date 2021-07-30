#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e5+100;
struct TREE{
    int l,r,w,tag;
}t[2][N<<2];
struct PotatoMINE{
    int x,y;
    const bool operator < (const PotatoMINE &rhs) const{
        if (x==rhs.x) return y>rhs.y;
        else return x<rhs.x;
    }
}mine[N];
vector <int> vec[N];
int n,m,k;
int pos[N];

void pushdown(int f,int x){
    if (t[f][x].tag==0) return;
    t[f][x<<1].w = t[f][x].tag * (t[f][x<<1].r-t[f][x<<1].l+1);
    t[f][x<<1|1].w = t[f][x].tag * (t[f][x<<1|1].r-t[f][x<<1|1].l+1);
    t[f][x<<1].tag = t[f][x<<1|1].tag = t[f][x].tag; 
    t[f][x].tag = 0;
}
void change(int x,int l,int r,int L,int R,int val){

}
int find(int f,int x,int l,int r,int p){
    if (l==r){
        t[f][x].tag=0;
        return x;
    }
    pushdown(f,x);
    int mid = (l+r)>>1;
    if (p<=mid) return find(f,x<<1,l,mid,p);
    else return find(f,x<<1|1,mid+1,r,p);
}
int getfirst(int f,int x){
    int now = find(f,1,1,n,x);
    while (now/2>0){
        int w = now % 2 == 1;
        now/=2; 
        if (!w && t[f][now<<1|1].w<(t[f][now<<1|1].r-t[f][now<<1|1].l+1)) {
            break;
        }
    }
    while (now==1 && t[f][now<<1|1].w<(t[f][now<<1|1].r-t[f][now<<1|1].l+1) ) return n+1;
    now = now<<1|1;
    while (t[f][now].l!=t[f][now].r){
        if (t[f][now<<1].w < t[f][now<<1].r-t[f][now<<1].l+1) now = now<<1;
        else now = now<<1|1;
    }
    return now;
}
void solve(){
    cin>>n>>m>>k;
    for (int i=1;i<=k;i++){
        cin>>mine[i].x>>mine[i].y;
    }
    sort(mine+1,mine+1+k);
    for (int i=1;i<=k;i++){
        vec[mine[i].x].push_back(mine[i].y);
    }
    int rr = 0;
    int alive = 0;
    for (int i=1;i<=n;i++){
        change(i&1,1,n,1,n,0);
        int len = vec[i].size();
        for (int j=0;j<len;j++){
            if (vec[i][j]<=rr+1){
                rr = max(rr,vec[i][j]);
                break;
            }
            int p = getfirst((i&1)^1,vec[i][j]);
            if (p>vec[i][j]+1){
                change(i&1,1,n,vec[i][j],p-1,1);
            }
        }
        if (rr>0)
            change(i&1,1,n,1,rr,1);
        alive += t[i&1][1].w;
    }
    cout<<alive<<"\n";
    return;
}
int main(){
    int T;
    while (cin>>T) solve();
}