#include <bits/stdc++.h>
using namespace std;
const int N = 2e3+100;
int black[N][N];
int n,m;
int T;

int getans(int x1,int y1,int x2,int y2){
    x1--; y1--;
    return black[x2][y2]-black[x2][y1]-black[x1][y2]+black[x1][y1];
}

void solve(){
    // 蓝名狗全是沙比癌症晚期没什么实力
    // 上不去下不来这段位自己也知道自己
    cin>>n>>m;
    for (int i=0;i<=n;i++){
        for (int j=0;j<=m;j++){
            black[i][j]=0;
        }
    }
    for (int i=1;i<=n;i++){
        string s;
        cin>>s;
        for (int j=1;j<=m;j++){
            black[i][j]=black[i-1][j]+black[i][j-1]-black[i-1][j-1]+(s[j-1]=='1'); 
        }
    }
    
    int minn = 16;
    for (int x2=5;x2<=n;x2++){
        for (int y2=4;y2<=m;y2++){
            for (int x1=x2-4;x1>=1;x1--){
                for (int y1=y2-3;y1>=1;y1--){
                    int inside = getans(x1+1,y1+1,x2-1,y2-1);
                    int blk_up_down = getans(x2,y1+1,x2,y2-1)+ getans(x1,y1+1,x1,y2-1);
                    blk_up_down = (y2 - y1 - 1) * 2 - blk_up_down;

                    int blk_lr = getans(x1+1,y2,x2-1,y2)+getans(x1+1,y1,x2-1,y1);
                    blk_lr = (x2-x1 - 1)*2 - blk_lr;
                    int ans2 = inside +  (y2 - y1 - 1) + (x2-x1 - 1) - getans(x2,y1+1,x2,y2-1) - getans(x1+1,y2,x2-1,y2);
                    int ans = inside + blk_lr + blk_up_down;
                    if (ans2>=17) {
                        break;
                    }
                    minn = min(minn,ans);
                }
            }
        }
    }
    cout<<minn<<"\n";
}
int main(){
    cin>>T;
    while (T--) solve();
    return 0;
}