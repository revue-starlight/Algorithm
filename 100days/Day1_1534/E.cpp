#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
int vis[N];
int dep[N];
int f = 1;
int pre[N];
vector <int> vec;
vector <int> popb,popw;
stack <int> bb,ww;
int main(){
    int n,k;
    cin>>n>>k;
    queue <int> q;
    q.push(0);
    while (!q.empty()){
        int b = q.front(); q.pop();
        vis[b] = 1;
        if (b==n){
            int x = b;
            while (x != 0){
                vec.push_back(x);
                x = pre[x];
            }
                f = 0;
            break;
        }
        int w = n-b;
        for (int x = max(0,k-w); x<=min(b,k);x++){
            int v = b - x + k - x;
            if (!vis[v]){
                vis[v]=1;
                dep[v]=dep[b]+1;
                pre[v]=b;
                q.push(v);
            }
        }
    }
    if (f==1){
            cout<<"-1";
            return 0;
        }
    int pre = 0;
    for (int i=1;i<=n;i++) ww.push(i);
    int sum=0;
    for (int i=vec.size()-1;i>=0;i--) {
        int now = vec[i];
        int x = (now - pre + k);
        x /=2;
        popb.clear(); popw.clear();
        //x popblack k-x popwhite
        cout<<"? ";
        for (int ii=0;ii<(k-x);ii++){
            popb.push_back(bb.top()); bb.pop();
            cout<<popb[ii]<<" ";
        }
        for (int ii=0;ii<x;ii++) {
            popw.push_back(ww.top()); ww.pop();
            cout<<popw[ii]<<" ";
        }
        cout<<"\n";
        int xx;
        cin>>xx; sum^=xx;
        for (int ii=0;ii<(k-x);ii++){
            ww.push(popb[ii]);
        }
        for (int ii=0;ii<(x);ii++){
            bb.push(popw[ii]);
        }
        pre = now;
    }
    cout<<"!\n";
    cout<<sum<<endl;
    return 0;
}