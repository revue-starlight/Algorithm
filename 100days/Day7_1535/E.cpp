#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+100;
vector <int> son[N];
struct Tree{
    int fa,a,c;
}t[N];
int f2[21][N];
int tot=0;


signed main(){
    int q;
    cin>>q>>t[0].a>>t[0].c;
    tot = 1;
    for (int i=1;i<=q;i++){
        int ansR=0;
        int ansS=0;
        int type;
        cin>>type;
        if (type==1){
            int p,a,c;
            cin>>p>>a>>c;
            t[i]={p,a,c};
            // lca 核心  记牢了
            f2[0][i]=p;
            for (int j=1;j<20;j++){
                f2[j][i]=f2[j-1][f2[j-1][i]];
            }
        }
        if (type==2){
            int v,w; cin>>v>>w; 
            while (w>0 && t[v].a>0){
                int now = v;
                for (int j=20;j>=0;j--){
                    if (t[f2[j][now]].a>0) {
                        now = f2[j][now];
                    }
                }
                int mn = min(t[now].a,w);
                t[now].a-=mn;
                w-=mn;
                ansR += mn;
                ansS += mn * t[now].c;
            }
            cout<<ansR<<" "<<ansS<<endl;
        }
    }
    return 0;
}