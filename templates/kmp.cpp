#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+6;
int pre[N];
string s,t;
void getnxt(){
    int len = t.length();
    int j = -1;
    pre[0]=-1;
    for (int i=1;i<len;i++){
        while (t[j+1]!=t[i] && j!=-1) j=pre[j];
        if (t[j+1]==t[i]) j++;
        pre[i]=j;
    }
}
int n,M;
int main(){
    cin>>n>>M;
    cin>>s;
    t=s;
    getnxt();
    int pos=s.length();
    for (int i=1;i<t.length();i++){
        if (pos!=s.length()) break;
        int j = pre[i-1];
        while (j!=-1){
            if (t[j+1]<t[i]){
                pos = i - j - 1;
                break;
            }
            j = pre[j];
        }
        if (s[0]<s[i]) {
            pos = i;
            break;
        }  
    }
    if (pre[t.length()-1] == pre[t.length()-2])
    for (int i=0;i<M;i++){
        cout<<s[i%pos];
    }
    return 0;
}