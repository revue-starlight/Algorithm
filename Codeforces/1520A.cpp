#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while (T--){
        int n,k;
        cin>>n;
        string s;
        cin>>s;
        int a[199];
        memset(a,0,sizeof(a));
        a[s[0]]=1;
        int flag=1;
        for (int i=1;i<n;i++){
            if (s[i]!=s[i-1]){
                if (a[s[i]]!=0) {
                    flag = 0;
                    break;
                }
                a[s[i]]=1;
            }
        }
        if (flag) {
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
        
    }
    return 0;
}