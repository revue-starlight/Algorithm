#include <bits/stdc++.h>
using namespace std;
const int N = 10;
struct aaa{
    int val,id;
    const bool operator < (const aaa &rhs) const {
        return id<rhs.id;
    }
}a[N];
int gett[N];
int main(){
    freopen("make.in","r",stdin);
    freopen("1.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        gett[i]=i;
    }
    for (int i=1;i<=m;i++){
        int id,val;
        cin>>id>>val;
        a[i]={val,id};
    }
    sort(a+1,a+1+m);
    do{
        stack <int> st;
        int point = 1;
        int flag = 1;
        for (int i=1;i<=n;i++){
            while (!st.empty() && st.top()>gett[i]) st.pop();
            st.push(gett[i]);
            if (i==a[point].id){
                if (a[point].val!=st.size()) {flag=0;break;}
                point++;
            }
        }
        if (flag==1){
            for (int i=1;i<=n;i++){
                cout<<gett[i]<<" ";
            }
            return 0;
        }
    } while (next_permutation( gett+1, gett+1+n ));
    cout<<-1<<endl;
}