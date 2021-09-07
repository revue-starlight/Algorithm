#include <bits/stdc++.h>
using namespace std;
int main(){
    srand(time(NULL));
    int n = rand()%10+1;
    int k = rand()%101;
    double p = 1.0*k/100;
    cout<<n<<" "<<p<<endl;
    for (int i=1;i<=n;i++){
        int p = rand()%10000000+1;
        cout<<p<<" ";
    }
    cout<<"\n";
    return 0;
}