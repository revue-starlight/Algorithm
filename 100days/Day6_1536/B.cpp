#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;
vector <int> vec;

void printt(int x){
    string s="";
    while (x){
        int p = x%26;
        if (p==0) p=26;
        char ch = (char)(p+'a'-1);
        s.push_back(ch);
        x-=x%27;
        x/=26;
    }
    for (int i=s.length()-1;i>=0;i--){
        cout<<s[i];
    }
    cout<<endl;
}
int make(string x){
    int ret=0;
    for (int i=0;i<x.length();i++){
        ret=ret*26+(int)(x[i]-'a'+1);
    }
    return ret;
}
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    for (int i=1;i<=s.length();i++){
        vec.clear();
        for (int p1 = 0;p1<s.length();p1++){
            int p2 = p1+i-1;
            if (p2>=s.length()) break;
            vec.push_back(make(s.substr(p1,i)));
        }
        sort(vec.begin(),vec.end());
        string st="",ed="";
        for (int ii=0;ii<i;ii++) st+="a",ed+="z";
        if (vec[0]!=make(st)){
            cout<<st<<endl;
            return;
        }
        for (int i=1;i<vec.size();i++){
            if (vec[i]!=vec[i-1]+1 && vec[i]!=vec[i-1]){
                printt(vec[i-1]+1);
                return;
            }
        }
        if (vec[vec.size()-1]!=make(ed)){
            printt(vec[vec.size()-1]+1);
            return;
        }
    }
}
signed main(){
    cin>>T;
    while (T--) solve();
    return 0;
}