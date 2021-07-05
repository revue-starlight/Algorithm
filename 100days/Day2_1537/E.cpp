#include <bits/stdc++.h>
using namespace std;
int n,k; string s;
int main(){
    cin>>n>>k;    
    cin>>s;
    int pos = s.length();
    for (int i=1;i<=s.length();i++){
        if (s.substr(0,i)+s.substr(0,i) < (s+s).substr(0,i*2)) {
            pos = i;
            break;
        }
    }
    for (int i=0;i<k;i++){
        cout<<s[i%pos];
    }
    return 0;
}