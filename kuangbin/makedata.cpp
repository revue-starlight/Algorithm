#include <bits/stdc++.h>
using namespace std;
int main(){
    srand(time(NULL));
    int T = 10;
    cout<<10<<endl;
    for (int i=1;i<=T;i++){
        int n = 100000;
        int q = 100000;
        cout<<n<<" "<<q<<"\n";
        while (q--){
            int l = rand()%n+1,r=rand()%n+1;
            if (l>r) swap(l,r);
            cout<<l<<" "<<r<<" "<<rand()%3+1<<"\n";
        }
    }
}