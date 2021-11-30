#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+100;
int T;
pair<int,int> ans2[N];
stack <int> st1,st2;
int ans = 0;

struct bcj{
    int f[N];
    int find(int x){return (x==f[x])?x:f[x]=find(f[x]);}
    bool same(int x,int y){return find(x)==find(y);}
    void init(int n){for (int i=1;i<=n;i++) f[i]=i;}
    void uni(int x,int y){f[find(x)]=y;}
}bcj1,bcj2;

void solve(){
    int tot;
    int n,m;
    cin>>tot>>n>>m;
    bcj1.init(tot); bcj2.init(tot);
    for (int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        bcj1.uni(x,y);
    }
    for (int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        bcj2.uni(x,y);
    }
    int cnt=0;
    for (int i=1;i<=tot;i++){
        if (!bcj1.same(1,i) && !bcj2.same(1,i)){       
            bcj1.uni(1,i); bcj2.uni(1,i);
            ans2[++ans] = (make_pair(1,i));
            cnt++;
        }
    }
    int cnt1 = 0;
    for (int i=2;i<=tot;i++){
        if (!bcj1.same(1,i)) st1.push(i);
        if (!bcj2.same(1,i)) st2.push(i);
        if (!st1.empty() && !st2.empty()){
            int a = st1.top(), b= st2.top();
            ans2[++ans] =(make_pair(st1.top(),st2.top()));
            bcj1.uni(a,b); bcj2.uni(a,b);
            st1.pop(); st2.pop();
        }
    }
    
    cout<<ans<<"\n";
    for (int i=1;i<=ans;i++){
        pair <int,int> s = ans2[i];
        cout<<s.first<<" "<<s.second<<"\n";
    }    
}
signed main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //cin>>T;
    T = 1;
    while(T--)solve();
}