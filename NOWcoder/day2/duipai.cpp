#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N = 10;
struct aaa{
    int val,id;
    const bool operator < (const aaa &rhs) const {
        return id<rhs.id;
    }
}a[N];
int gett[N];
int main(){
    int cntt = 0;
  while (1){
      cntt++;
      cout<<"cnt:"<<cntt<<":";
        system("./make");
        system("./Kbaoli");
        system("./K");
        freopen("1.out","r",stdin);
        int x;
        cin>>x;
        if (x==-1){
            if (system("diff 1.out 2.out")){
            printf("Wrong Answer\n");
            return 0;
            }
            else printf("Accepted\n");
        }
        else {
            freopen("make.in","r",stdin);
            int n,m;
            cin>>n>>m;
            for (int i=1;i<=m;i++){
                int id,val;
                cin>>id>>val;
                a[i]={val,id};
            }
            sort(a+1,a+1+m);

            freopen("2.out","r",stdin);

            int x,cnt=1;
            for (int i=1;i<=n;i++) cin>>gett[i];
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
                printf("Accepted\n");
            } else {
                return 0;
            }
            }
    }
    return 0;
}