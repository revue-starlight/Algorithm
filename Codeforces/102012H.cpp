#include <bits/stdc++.h>
using namespace std;
const int N = 8e5+10;
struct a102012H{
    int pos,id,in;
    const bool operator < (const a102012H BB){
        return pos<BB.pos;
    }
}e[N];
struct aaa{
    int pos,id;
    const bool operator < (const aaa BB) const {
        return pos>BB.pos;
    }
};
int T;
int n,k;
int stocolor[N];
pair <int,int> a[N];
void solve(){
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        int p;
        int q;
        cin>>p>>q;
        a[i].first = p;
        a[i].second = q;
        e[i*2-1]={p,i,1};
        e[i*2]={q,i,0};
    }
    sort(e+1,e+1+n*2);
    stack <int> co;
    priority_queue <aaa> sg;
    int last;
    vector <pair<int,int>> vec;
    int tot=0;
    for (int i=1;i<=k;i++) co.push(i);
    last = 0x3f3f3f3f;
    for (int i=1;i<=2*n;i++){
        if (e[i].in == 1){// push_something
            if (co.empty()){// color empty
                if (last == 0x3f3f3f3f)
                last = e[i].pos;
                sg.push({a[e[i].id].second,e[i].id});
            } else {
                stocolor[e[i].id]=co.top();
                co.pop();
            }
        } else {//pop_something
            if (e[i].id == sg.top().id) {sg.pop(); continue;}
            if (stocolor[e[i].id]!=0){
                co.push(stocolor[e[i].id]);
                if (!sg.empty()){
                    stocolor[sg.top().id]=co.top();
                    co.pop();
                    sg.pop();
                }
            }
            if (!co.empty()){
                vec.push_back(make_pair(last,e[i].pos));
                tot+=max(0,e[i].pos-last+1);
                last = 0x3f3f3f3f;
            }
        }
    }
    cout<<tot<<"\n";
    for (int i=1;i<=n;i++) cout<<max(stocolor[i],1)<<" ";
    cout<<"\n";
}

int main(){
    cin>>T;
    while (T--) solve();
}
