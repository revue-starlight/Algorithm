#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+10;
int a[N];
int T;
bool f = false;
vector <int> vec[8192];
struct Node{
    int xorVal,ind;
    bool operator < (const Node &rhs) const {
        return ind < rhs.ind;
    }
};
vector <Node> ans;
vector <Node> tmpvec;
int maxa_i;
void solve(){
    maxa_i = 0;
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++){
        vec[a[i]].push_back(i);
        maxa_i = max(a[i],maxa_i);
        if (vec[a[i]].size()>=2) f = true;
    }
    ans.push_back({0,-1});
    int tmp = 0;
    while ((1<<tmp)<=maxa_i) tmp++;
    int maxa = 1<<tmp;
    for (int i=0;i<maxa;i++){
        tmpvec.clear();
        int x = 0;
        for (auto s:ans){
            while (x!=vec[i].size() && vec[i][x] < s.ind) x++;
            if (x!=vec[i].size())
                tmpvec.push_back({s.xorVal^i,vec[i][x]});
        }
        vector <Node> newvec;
        int len1 = ans.size(), len2 = tmpvec.size();
        int pos1,pos2 = 0;
        int bucket[maxa];
        memset(bucket,0,sizeof(bucket));
        for (pos1=0;pos1<len1;pos1++){
            while (pos2!=len2 && tmpvec[pos2]<ans[pos1]){
                if (bucket[tmpvec[pos2].xorVal] == 0)
                    newvec.push_back(tmpvec[pos2]);
                bucket[tmpvec[pos2].xorVal] = 1;
                pos2++;
            }
            if (bucket[ans[pos1].xorVal] == 0)
                newvec.push_back(ans[pos1]);
            if (ans[pos1].ind != -1)
                bucket[ans[pos1].xorVal] = 1;
        }
        while (pos2!=len2){
            if (bucket[tmpvec[pos2].xorVal] == 0)
                newvec.push_back(tmpvec[pos2]);
            bucket[tmpvec[pos2].xorVal] = 1;
            pos2++;
        }
        ans = newvec;
    }

    int bucket[maxa];
    memset(bucket,0,sizeof(bucket));
    bucket[0] = 1;

   // cout<<ans.size()-1<<"\n";
    for (auto s:ans){
        if (s.ind>0)
            bucket[s.xorVal] = 1;
    }
    vector <int> outputt;

    for (int i=0;i<maxa;i++){
        if (bucket[i]==1){
            outputt.push_back(i);
        }
    }
    cout<<outputt.size()<<"\n";
    for (auto s:outputt) cout<<s<<" ";
    cout<<"\n";

}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //cin>>T;
    T = 1;
    while(T--)solve();
}