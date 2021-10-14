#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,q;
int us[1005][1005];
bool out(int x,int y){
    if (x<1 || x>n || y<1 || y>m) return 1;
    return 0;
}
bool vis(int x,int y){
    return (us[x][y]==1);
}
const int FX[2][2]={{1,0},{0,1}};
const int FXU[2][2]={{-1,0},{0,-1}};
int getlen(int x,int y,int fx){
    if (out(x,y)) return 0;
    if (vis(x,y)) return 0;
    return 1+getlen(x+FX[fx][0],y+FX[fx][1],fx^1);
}
int getUlen(int x,int y,int fx){
    if (out(x,y)||vis(x,y)) return 0;
    return 1+getUlen(x+FXU[fx][0],y+FXU[fx][1],fx^1);
}
int ans = 0;
void solve(){
    cin>>n>>m>>q;
    for (int i=1;i<m;i++){
        int tmp = getlen(1,i,1);
        ans+= tmp*(tmp-1)/2;
    }
    for (int i=1;i<n;i++){
        int tmp = getlen(i,1,0);
        ans+= tmp*(tmp-1)/2;
    }
    ans+=n*m;
    while (q--){
        int x,y;
        cin>>x>>y;
        int una = 1;
        if (!vis(x,y)) una = -1; 
        int ff = 0;
        if (us[x][y]==1) {us[x][y]^=1; ff = 1;}
        int up = getUlen(x,y,0)-1;//upper,,,
        int down = getlen(x,y,1)-1;
        ans+=(up*down+up+down)*una;
        up = getUlen(x,y,1)-1;
        down = getlen(x,y,0)-1;
        ans+=(up*down+up+down)*una;
        if (ff==0) us[x][y]^=1;
        ans+=una;
        cout<<ans<<"\n";
    }   
}
signed main(){
    solve();
}