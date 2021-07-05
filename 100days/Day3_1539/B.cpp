#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100004][50];
void solve(){
    int n,q;
    string s;
    cin>>n>>q>>s;
    s = " "+s;
    for (int i=1;i<=n;i++){
        int p = s[i]-'a';
        for (int j=0;j<='z'-'a';j++){
            a[i][j]=a[i-1][j];
        }
        a[i][p]++;
    }
    while (q--){
        int l,r;
        cin>>l>>r;
        int sum = 0;
        for (int i=0;i<='z'-'a';i++){
            sum = sum+(i+1)*(a[r][i]-a[l-1][i]);
        }
        cout<<sum<<endl;
    }
}
signed main(){
solve();
}