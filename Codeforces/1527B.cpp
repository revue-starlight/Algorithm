#include <bits/stdc++.h>
using namespace std;
int T;
int num0;
bool check(string s){
    int l = 0, r = s.length()-1;
    while (l<r){
        if (s[l]!=s[r]) return false;
        l++; r--;
    }
    return 1;
}
int main(){
    cin>>T;
    int n;
    while (T--){
        cin>>n;
        num0=0;
        string s;
        cin>>s;
        for (int i=0;i<s.length();i++) if (s[i]=='0') num0++;
        if (num0==2 && s.length()%2==1 && s[s.length()/2]=='0') { cout<<"DRAW\n"; continue;}
        if (check(s)){
            if (num0==0) {cout<<"DRAW\n";}
            else if (num0==1) {cout<<"BOB\n";}
            else if (num0%2==0) {cout<<"BOB\n";}
            else if (num0%2==1) {cout<<"ALICE\n";}
        } else {
            cout<<"ALICE\n";
        }
    }
}