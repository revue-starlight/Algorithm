#include <bits/stdc++.h>
using namespace std;
int T;
int a[200005];
void solve(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int minn = 1e9+1,id=-1;
    for (int i=0;i<n-1;i++){
        if (a[i+1]-a[i]<minn) minn=a[i+1]-a[i],id=i;
    }
    cout<<a[id]<<" ";
    for (int i=id+2;i<n;i++) cout<<a[i]<<" ";
    for (int i=0;i<id;i++) cout<<a[i]<<" ";
    cout<<a[id+1];
    cout<<"\n";
}
int main(){
    cin>>T;
    while (T--) solve();
}