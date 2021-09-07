#include <bits/stdc++.h>
using namespace std;
int main(){
    
    double n;
    while (cin>>n){
    if (n<=-5){
        n-=0.2;
    } else if (n<=2.5){
        n-=0.1;
    } else if (n<=12.5){
        n-=0.0;
    } else if (n<=25){
        n-=0.1;
    } else if (n<=40){
        n-=0.0;
    } else if (n<=50){
        n+=0.1;
    }
    cout<<n<<'\n';
    }
}