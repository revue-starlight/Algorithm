#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("C:\\Users\\19606\\Documents\\desktop\\desktop\\luogu\\test.in","w",stdout);
    srand(time(NULL));
    int n=rand()%10+1,m=rand()%10+1;
    cout<<n<<endl;
    for (int i=1;i<=n;i++){
        int p = rand()%10+1;
        if (p<=5) cout<<1<<" "; else
        cout<<rand()%10+1;
    }
    cout<<endl;
    cout<<m<<endl;
    while (m--){
        int a=rand()%n+1,b=rand()%n+1;
        cout<<min(a,b)<<" "<<max(a,b)<<endl;
    }
}