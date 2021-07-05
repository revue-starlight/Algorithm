#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while (T--){
        int n,m,x,y;
        cin>>n>>m>>x>>y;
        double t1=(double)(n-m)*1.0/(double)(x+y);
        double t2;
        if (x<y){
            t2=1.0*m/(1.0*(y-x));
        }
        if (x==y) t2=INT_MAX;
        if (x>y) t2=(1.0*(n-m))/(1.0*(x-y));
        cout<<fixed<<setprecision(10)<<min(t1,t2)<<endl;
    }
}