#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;
const int N = 1e5+100;
int a[N];
vector <int> vec;
void solve(){
    int n;
    cin>>n;
    int maxx=numeric_limits<int>::min();
    int minn=numeric_limits<int>::max();
    vec.clear();
    for (int i=1;i<=n;i++){
        cin>>a[i];
        minn=min(minn,a[i]);
        maxx=max(maxx,a[i]);
    }
    for (int i=1;i<=n;i++){
        if (a[i]==minn) vec.push_back(i);
        if (a[i]==maxx) vec.push_back(i);
    }
    int gap = numeric_limits<int>::min();
    for (int i=1;i<vec.size();i++){
        gap = max(gap,vec[i]-vec[i-1]);
    }
    int ret = n-(gap-1);
    ret = min(ret,vec[vec.size()-1]);
    ret = min(ret,n-vec[0]+1);
    cout<<ret<<endl;
}
signed main(){
    cin>>T;
    while (T--) solve();
    return 0;
}