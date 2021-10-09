#include <bits/stdc++.h>
using namespace std;
struct pp{
    int id,val;
    const bool operator < (const pp rhs) const{
        return val<rhs.val;
    }
};
int main(){
    int T;
    cin>>T;
    while (T--){
        vector <pair<int,int>> pi;
        int n;
        cin>>n;
        priority_queue<pp> q;
        for (int i=1;i<=n;i++){
            int x;
            cin>>x;
            if (x>0) q.push({i,x});
        }
        while (q.size()>1){
            pp a = q.top();
            q.pop();
            pp b = q.top();
            q.pop();
            pi.push_back({a.id,b.id});
            a.val--; b.val--;
            if (a.val>0) q.push(a);
            if (b.val>0) q.push(b);
        }
        
        cout<<pi.size()<<"\n";
        if (pi.size()>0){
            for (auto ppp:pi){
                cout<<ppp.first<<" "<<ppp.second<<"\n";
            }
        }
    }
}