// 438 --- std 426
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+100;
int T;
int n,k;
int a[N];
int pos[N<<5],son[N<<5][2];
int tot;
int rpos;
void solve(){
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        a[i]^=a[i-1];
    }
    tot = 1;
    int minn = numeric_limits<int>::max();
    son[1][0]=son[1][1]=0;
    for (int i=1;i<=n;i++){
        int now = 1;
        for (int j=29;j>=0;j--){
            int w = (a[i]>>j)&1;
            if (son[now][w]) now = son[now][w];
            else {
                son[now][w]=++tot;
                son[tot][0]=son[tot][1]=0;
                now = son[now][w];
            }
            pos[now]=i;
        }
        now = 1;
        for (int j=29;j>=0;j--){
            int w = (a[i]>>j)&1;
            int K = (k>>j)&1;
            if (K==0){
                if (son[now][w^1]!=0) {
                    if ((i-pos[son[now][w^1]]<minn)) minn = i-pos[son[now][w^1]],rpos=i;
                }
                now = son[now][w];
            } else now = son[now][w^1];
            if (!now) break;
        }
        if (now) {
            if ((i-pos[now]<minn)) minn = i-pos[now],rpos=i;
        }
    }
    if (minn!=numeric_limits<int>::max()){
        cout<<rpos-minn+1<<" "<<rpos<<"\n";
    } else cout<<"-1\n";
}
signed main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while (T--) solve();    
}