#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int tot=0;
    for (int i=0;i<s.length();i++){
        if (tot<(s[i]-'0')) tot=s[i]-'0';
    }
    cout<<tot;
}