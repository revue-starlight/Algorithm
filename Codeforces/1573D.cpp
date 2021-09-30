#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int cal(int len,int pos){
    return (len-1)/2+max(0,(len-3)/2);
}
int work(int len,int pos){
    int i;
    int cnt =  0;
    
    for (i=1;i<=len-2;i+=2){
        cout<<i+pos<<" ";
    }
    for (i=len-4;i>=1;i-=2){
        cout<<i+pos<<" ";
    }
    
    return 0;
}
void solve(){
    cin>>n;
    string s;
    int cnt = 0;
    for (int i=1;i<=n;i++){
        char ch;
        cin>>ch;
        if (ch == '1') cnt++;
        s+=ch;
    }
    if (cnt%2==1) {
        cout<<"NO\n"; return;
    }
    if (n%2==1){
        cout<<"YES\n";
        cout<<cal(n,0)<<"\n";
        work(s.length(),0);
        cout<<"\n";
        return;
    } else {
        cnt = 0;
        for (int j=0;j<n;j+=2){
            if (j>0){
                cnt+=(s[j-1]=='1');
            }
            cnt+=(s[j]=='1');
            if (cnt%2==0){
                 cout<<"YES\n";
                cout<<cal(j+1,0)+cal(n-j-1,j+1)<<"\n";
                work(j+1,0);
                work(n-j-1,j+1);
                 cout<<"\n";
                 return;
            }
        }
    }                   
    cout<<"NO\n";
}
int main(){
    int T;
    cin>>T;
    while (T--) solve();
}