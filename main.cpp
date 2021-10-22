#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int even[N],odd[N];
int main(){
    int t;
    cin>>t;
    while (t--){
        string s;
        cin>>s;
        for (int i=0;i<s.length();i++){
            even[i+1]=even[i];
            odd[i+1]=odd[i];
            if (s[i]=='[' || s[i]==']'){
                if (i&1 == 1){
                    even[i+1]++;
                } else odd[i+1]++;
            }
        }
        int q;
        cin>>q;
        while (q--){
            int l,r;
            cin>>l>>r;
            cout<<abs(even[r]-even[l-1]-odd[r]+odd[l-1])<<"\n";
        }
    }
    return 0;
}