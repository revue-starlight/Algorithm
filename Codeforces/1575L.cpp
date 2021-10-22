#include <bits/stdc++.h>
#define int long long
using namespace std;
struct stc{
    int v,idv;
    bool operator < (const stc bb) const {
        if (idv==bb.idv) 
            return v<bb.v;
        bool bo = (idv<=bb.idv);
        return bo;
    }
};
vector <stc> v;
int n;
vector <int> lis;
signed main(){
    cin>>n;
    v.resize(n+1);
    v[0]={0,0};
    for (int i=1;i<=n;i++) {cin>>v[i].v; v[i].idv=i-v[i].v;}
    sort(v.begin()+1,v.end());
    
    for (int i=1;i<=n;i++){
        if (v[i].idv<0) continue;
        if (lis.empty()) lis.push_back(v[i].v);
        else {
            if (lis.back()<v[i].v) lis.push_back(v[i].v);
            else {
                int p = lower_bound(lis.begin(),lis.end(),v[i].v)-lis.begin();
                lis[p]=v[i].v;
            }
        }
    }
    cout<<lis.size()<<"\n";
}