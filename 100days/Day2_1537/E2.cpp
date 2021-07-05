#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int i=1,j=0;
    s = s+s;
    int M = n;
    while (1){
        if (j==n) break;
        if (s[i]==s[j]) i++,j++;
        else if (s[i]<s[j]) i++,j=0;
        else if (s[i]>s[j]) {
            M = i-j;
            break;
        }   
    }
    for (int i=0;i<k;i++){
        cout<<s[i%M];
    }
    return 0;
}