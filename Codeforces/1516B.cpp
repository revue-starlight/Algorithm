#include <bits/stdc++.h>
using namespace std;
long long T;
int main(){
    cin>>T;
    while (T--){
        long long n;
        cin>>n;
        long long a[2005]; 
        long long pre[2005];
        long long bck[2005];
        for (long long i=1;i<=n;i++){
            cin>>a[i];
        }
        pre[0]=pre[n+1]=0;
        for (long long i=1;i<=n;i++){
            pre[i]=a[i]^pre[i-1];
        }
        long long flag=0;
        for (long long i=1;i<n;i++){
            long long a=pre[i];
            long long b=pre[n]^pre[i];
            if (pre[i]==(pre[n]^pre[i]))
                {cout<<"YES\n"; flag=1; break;}
        }
        if (!flag)
            for (long long i=1;i<=n;i++){
                for (long long j=i+1;j<n;j++){
                    if (pre[i]==(pre[j]^pre[i]) && pre[i]==(pre[n]^pre[j])){
                        cout<<"YES\n"; flag=1; break;
                    }
                }
                if (flag==1) break;
            }
        if (!flag) cout<<"NO\n";
    }
    return 0;
}