#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+100;
int T;
int n,k;
int a[N];
int val[N][2];
void solve(){
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=n;i++){
        for (int j=19;j>=0;j--){
            int w = (a[i]>>j)&1;
            
        }
    }
}
int main(){
    cin>>T;
    while (T--) solve();    
}