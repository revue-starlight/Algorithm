#include <bits/stdc++.h>
using namespace std;
const int p[]={7,27,41,49,63,78,108};
int main(){
    int T;
    cin>>T;
    while (T--){
        int n;
        cin>>n;
        int tot  =0;
        for (int i=0;i<n;i++){
            int x;
            cin>>x;
            tot+=p[x-1];
        }
        if (tot>=120) {
            tot-=50;
        } else if (tot>=89){
            tot-=30;
        } else if (tot>=69){
            tot-=15;
        }
        cout<<tot<<"\n";
    }
    return 0;
}