#include <bits/stdc++.h>
using namespace std;
int main(){
    srand(time(NULL));
    int n = 1e5;
    int m = 1e6;
    cout<<n<<"\n";
    vector <int> vec;
    for (int i=1;i<=n;i++){
        int x = rand()%m+1;
        vec.push_back(x);
    }
    sort(vec.begin(),vec.end());
    for (auto s:vec){
        cout<<s<<" ";
    }
    cout<<"\n"<<n<<"\n";
    while (n--){
        cout<<rand()%m+1<<"\n";
    }
    return 0;
}