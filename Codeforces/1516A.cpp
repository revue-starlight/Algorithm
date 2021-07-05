#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while (T--){
        int n,k;
        cin>>n>>k;
        int a[105];
        for (int i=1;i<=n;i++) cin>>a[i];
        for (int i=1;i<n;i++){
            if (k-a[i]>=0){
                a[n]+=a[i];
                k-=a[i];
                a[i]=0; 
            }
            else{
                a[n]=a[n]+k;
                a[i]=a[i]-k;
                break;
            }
        }
        for (int i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<"\n";
    }
    return 0;
}