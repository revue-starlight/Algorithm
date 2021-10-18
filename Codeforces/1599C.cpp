#include <bits/stdc++.h>
using namespace std;
int n;
double P;
const double K = 1e-10;
double getC(int a,int b){
    if (b>a) return 0.0;
    else {
        if (b==1) return 1.0*a;
        else return 1.0*a*(a-1)/2;
    }
}
int main(){
    cin>>n>>P;
    long long cn33 = n*(n-1)*(n-2)/6;
    double cn3 = 1.0*n*(n-1)*(n-2)/6.0;
    double p = 0;
    for (int k=0;k<n;k++){
        if (p+K>=P) {
            cout<<k<<endl;
            return 0;
        }
        p+=getC(n-k-1,2)/2.0/cn3+getC(n-k-1,1)*getC(k,1)/2.0/cn3;
    }
    return 0;
}