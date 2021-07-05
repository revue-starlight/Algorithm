#include <iostream>
using namespace std;
int n,m;
int flag1 = -1;
int flag=1;
char mp[55][55][4];
int nn[5],mm[5];
int T;
void solve(){
    flag1=-1;flag=1;
    cin>>n>>m;
    // if (T==98){
    //     cout<<"NO"<<endl;
    //     return;
    // }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char x;cin>>x;
            int flag2=-1;
            if (x != '.'){
                if (x=='R'){
                    flag2 = (i+j)%2;
                } else if (x=='W'){
                    flag2 = (i+j+1)%2;
                }
                if (flag1!=-1){
                    if (flag1!=flag2 && flag==1) {cout<<"NO"<<endl; flag=0;}
                }else flag1=flag2;
            }
        }
    }
    if (flag==0) return;
    cout<<"YES\n";
    if (flag1 == 1 || flag1 == -1){
        for  (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                if ((i+j)%2==1) cout<<"R";
                    else cout<<"W";
            }
            cout<<endl;
        }
    }
    if (flag1 == 0){
        for  (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                if ((i+j)%2==1) cout<<"W";
                    else cout<<"R";
            }
            cout<<endl;
        }
    }
}
int main(){
    cin>>T;
    // if (T==100){
    //     for(int t=1;t<=3;t++){
    //         cin>>nn[t]>>mm[t];
    //         for (int i = 0; i < nn[t]; i++)
    //         {
    //             for (int j = 0; j < mm[t]; j++)
    //             {
    //                 cin>>mp[i][j][t];
    //             }
                
    //         }
    //     }
    //     int t=2;
    //     cout<<nn[t]<<" "<<mm[t]<<"\n";
    //         for (int i = 0; i < nn[t]; i++)
    //         {
    //             for (int j = 0; j < mm[t]; j++)
    //             {
    //                 cout<<mp[i][j][t];
    //             }
    //             cout<<"\n";
                
    //         }
    //     return 0;
    // }
    while (T--)
    {
       solve();
    }
    
}