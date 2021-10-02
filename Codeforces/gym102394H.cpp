#include <bits/stdc++.h>
using namespace std;
const int N = 6;
int mp[N][N];
const int fx[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
int n,m;
int tot = 0;
bool hefa(int x,int y){
    if (x<=0 || x>n || y<=0 || y>m) return false;
    return true;
}
bool check(int x,int y,int val){
    if (mp[x][y]!=0) return false;
    for (int i=0;i<4;i++){
        int nx,ny;
        nx = x+fx[i][0]; ny = y+fx[i][1];
        if (hefa(nx,ny) && mp[nx][ny]==val) return false;
    }
    return true;
}
int ans = 0;
void print(){
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++) cout<<mp[i][j];
        cout<<"\n";
    }
    cout<<"\n";
}
void dfs(int x,int y){
    if (tot == n*m-1){
        //print();
        ans++;
        return;
    }
    for (int i=0;i<4;i++){
        int nx,ny;
        nx = x+fx[i][0]; ny = y+fx[i][1];
        if (!hefa(nx,ny)) continue;
        for (int k=1;k<=3;k++){
            if (check(nx,ny,k)){
                mp[nx][ny]=k;
                tot++;
                dfs(nx,ny);
                tot--;
                mp[nx][ny]=0;
            }
        }
    }
}
int main(){
    for (n=2;n<=5;n++){
        for (m=2;m<=5;m++){
            ans=0;
            tot=0;
            memset(mp,0,sizeof(mp));
            mp[1][1]=1; 
            dfs(1,1);
            printf("%10d",ans);
        }
        printf("\n");
    }
    return 0;
}