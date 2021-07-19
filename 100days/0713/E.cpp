#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;
const int N = 3e5+100;
struct  Node{
    int val,id;
    bool operator < (const Node &b) const{
        return val<b.val;
    }
}a[N];
int now[N];
void solve(){
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        cin>>a[i].id;
    }
    for (int i=1;i<=m;i++){
        cin>>a[i].val;
    }
    a[m+1]={0,0};
    sort(a+1,a+m+1);
    for (int i=1;i<=n;i++) now[i]=0;
    queue <Node> q;
    int cnt = 1;
    while (a[cnt].val == a[cnt+1].val) q.push(a[cnt]),cnt++;
    q.push(a[cnt]); cnt++;
    while (!q.empty()){
        Node fr = q.front();
        q.pop();
        if (fr.val == a[cnt].val) {
            while (a[cnt].val == a[cnt+1].val) q.push(a[cnt]),cnt++;
            q.push(a[cnt]); cnt++;
        }
        if (now[fr.id]==0) {
            now[fr.id]=fr.val;
            Node a = {fr.val+1,fr.id-1};
            Node b = {fr.val+1,fr.id+1};
            if (a.id>=1 && a.id<=n) q.push(a);
            if (b.id>=1 && b.id<=n) q.push(b);
        }
    }
    for (int i=1;i<=n;i++) cout<<now[i]<<' ';
    cout<<endl;
}
signed main(){
    cin>>T;
    while (T--) solve();
    return 0;
}