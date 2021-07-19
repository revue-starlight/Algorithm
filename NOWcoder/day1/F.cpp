#include <bits/stdc++.h>
using namespace std;
#define int long long
int pre[100];
int work(int x){
    if (x<100) return pre[x];
    else return x-99+pre[99];
}
signed main(){
    int T;
    cin>>T;
    for (int i=1;i<100;i++){
        pre[i]=pre[i-1];
        if (i<10){
            if (i%3==0) pre[i]++;
            continue;
        }
        int a = i/10;
        int b = i%10;
        if (a%3==0 || b%3==0 || i%3==0){
            pre[i]++;
        }
    }
    while (T--){
        int l,r;
        cin>>l>>r;
        cout<<work(r)-work(l-1)<<endl;
    }
}