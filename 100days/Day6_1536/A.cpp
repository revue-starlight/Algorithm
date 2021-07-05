    #include <bits/stdc++.h>
    using namespace std;
    #define int long long
    int T;
    void solve(){
        int n;
        cin>>n;
        int minus=0,pos=0;
        for (int i=1;i<=n;i++){
            int x;
            cin>>x;
            if (x>0) pos=1;
            if (x<0) minus = 1;
        }
        if (pos>0 && minus>0){cout<<"NO\n";}
        else if (pos>0){
            cout<<"YES\n101\n";
            for (int i=0;i<=100;i++){
                cout<<i<<" ";
            }
            cout<<"\n";
        } else if (minus>0){
            cout<<"NO\n";
        } else {
            cout<<"YES\n"<<1<<"\n"<<"0\n";
        }
    }
    signed main(){
        cin>>T;
        while (T--) solve();
        return 0;
    }