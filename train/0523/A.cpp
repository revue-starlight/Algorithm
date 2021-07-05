#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int maxx = 100;
    int now = 100;
    for (int i=1;i<=n;i++){
        int p;
        cin>>p;
        now +=p;
        maxx =max(now,maxx);
    }
    cout<<maxx<<endl;
    return 0;
}