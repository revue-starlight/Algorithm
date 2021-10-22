#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
void solve(){
    string s;
    cin>>s;
    int n = s.length();
    s = " "+s;
    int now = 0;
    string t[4] = {"05","00","57","52"};
    int pos[4] = {0,0,0,0};
    int end[4] = {0,0,0,0};
    for (int i=n;i>=1;i--){
        for (int j=0;j<4;j++){
            if (pos[j]<=1 && t[j][pos[j]]==s[i]){
                pos[j]++;
                if (pos[j]==2){
                    end[j]=i;
                }
            }
        }
    }
    int k = 0;
    for (int i=0;i<4;i++) k = max(k,end[i]);
    int ans = n-k+1-2;
    cout<<ans<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--)solve();
}