#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while (T--){
        int n;
        cin>>n;
        int a[105][105];
        if (n==2){
            cout<<"-1\n";
            continue;
        }
        memset(a,0,sizeof(a));
        int cnt=0;
        for (int del=0;del<n;del++){
            int x=0,y=x+del;
            while (x<n && y<n){
                a[x][y]=++cnt;
                x++;y++;
            }
            if (del==0) continue;
            y=0;x=y+del;
            while (x<n && y<n){
                a[x][y]=++cnt;
                x++; y++;
            }
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}