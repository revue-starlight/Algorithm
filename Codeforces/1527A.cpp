#include <bits/stdc++.h>
using namespace std;
int T;
int main(){
    cin>>T;
    while (T--){
        int n;
        cin>>n;
        int p=1;
        while (p<=n) p*=2;
        p/=2;
        p--;
        cout<<p<<endl;
    }
    return 0;
}