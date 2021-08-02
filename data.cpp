#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("data.in","w",stdout);
    cout<<"1\n";
    srand(time(NULL));
    int n = rand()%20+1;
    cout<<n<<" "<<endl;
    for (int i=1;i<=n;i++){
            if (rand()%100>20)
            cout<<1;
            else cout<<0;
    }
        cout<<"\n";
    for (int i=1;i<=n;i++){
            if (rand()%100>80)
            cout<<1;
            else cout<<0;
    }
        cout<<"\n";
}