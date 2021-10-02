#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+100;
int n,m;
int x[N],y[N];
int diff[N];
int last[N];
int cnt[600][600];
void modify(int day,int k,int val){
    int l = day+x[k];
    int r = day+x[k]+y[k];
    int period = x[k]+y[k];
    l%=period;
    r%=period;
    if (r<l) r+=period;
    for (int i=l;i<r;i++){
        int p = i%period;
        cnt[period][p]+=val;
    }
}
int ans[N];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    int thres = sqrt(m);
    for (int i=1;i<=m;i++){
        int op,t;
        cin>>op>>t;
        if (op==1){
            if (thres<=x[t]+y[t]){
                for (int j=i+x[t];j<=m;j+=x[t]+y[t]){
                    diff[j]++;
                    if (j+y[t]<=m) diff[j+y[t]]--;
                }
            } else modify(i,t,1);
            last[t]=i;
        } else {
            int flag = 1;
            if (thres<=x[t]+y[t]){
                for (int j=last[t]+x[t];j<=m;j+=x[t]+y[t]){
                    if (j<i && j+y[t]>i){
                        diff[i]--;
                        if (j+y[t]<=m)
                            diff[j+y[t]]++;
                    }
                    if (j<i) continue;
                    diff[j]--;
                    if (j+y[t]<=m) diff[j+y[t]]++;
                }
            } else modify(last[t],t,-1);
        }
        int tt = 0;
        for (int j=1;j<thres;j++){
            tt+=cnt[j][i%j];
        }
        ans[i]+=tt;
    }
    for (int i=1;i<=m;i++){
        diff[i]=diff[i-1]+diff[i];
        ans[i]+=diff[i];
    }
    for (int i=1;i<=m;i++) cout<<ans[i]<<"\n";
    return 0;
}