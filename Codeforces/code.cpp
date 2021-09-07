#include <bits/stdc++.h>
using namespace std;
map <string,int> mp;
int main(){
    while (1){
        string s;
        cin>>s;
        if (s=="-1") break;
        else mp[s]++; 
        cout<<mp.size()<<"\n";
    }
}