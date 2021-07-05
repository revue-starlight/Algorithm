#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+100;
int a[N];
priority_queue <int> pq;
void solve(){
    int n,k,x;
    cin>>n>>k>>x;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for (int i=0;i<n-1;i++){
        if (a[i+1]-a[i]>x){
            pq.push(-(a[i+1]-a[i]));
        }
    }
    while (!pq.empty()){
        int dlt = pq.top();
        dlt = -dlt;
        if (k - ((dlt-1)/x) < 0) break;
        else {k = k - ((dlt-1)/x); pq.pop();}
    }
    cout<<pq.size()+1<<endl;
}
signed main(){
    int T;
    solve();
}