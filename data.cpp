#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
int b = 23;
const int &&a = 23;

string work(){
    string s = "34";
    return move(s);
}

signed main(){
    int n,k;
    srand(time(NULL));
    n = rand()%15+3;
    k = max(2ll,rand()%(n/3*2)+1);
    cout<<n<<" "<<k<<endl;
   for (int i=1;i<=n;i++){
       cout<<rand()%4+1<<" ";
   }
}