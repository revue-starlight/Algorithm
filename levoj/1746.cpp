#include <bits/stdc++.h>
using namespace std;
const int N =  100005;
int a[N];
int main(){
    int n,m;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    cin>>m;
    while (m--){
        int x;
        cin>>x;
        int q = upper_bound(a+1,a+1+n,x)-a;
        if (q==n+1) cout<<a[q-1]<<"\n";
        else if (q==1) cout<<a[1]<<"\n";
        else if (abs(a[q-1]-x)<=abs(a[q]-x)){
            cout<<a[q-1]<<"\n";
        } else cout<<a[q]<<"\n";
    }
}