#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    int T;
    cin>>T;
    while (T--){
        int n;
        cin>>n;
        int x;
        cin>>x;
        for (int i=1;i<n;i++){
            int p;
            cin>>p;
            x=x&p;
        }
        cout<<x<<endl;
    }
}