#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while (T--){
        int n;
        vector <int> vec;
        vec.push_back(-1);
        for (int i=1;i<=n;++i){
            int x;
            cin>>x;
            vec.push_back(x);
        }
        int cnt = 0;
        for (int i=1;i<=n;++i){
            int j;
            for (j=1;j<=n;j++){
                if (vec[i]==j)
                  break;  
            }
            if (j!=1) {
                cnt++;
                reverse(vec.begin()+1,vec.begin()+j);
                
            }
            
        }
    }
}