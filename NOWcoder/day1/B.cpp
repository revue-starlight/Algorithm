#include <bits/stdc++.h>
using namespace std;
double r,a,b,h;
double H;
double minR;
double cosa;
double sina;
double get_h(double s){
    double h = s * H / a;
    return h;
}

int main(){
    cin>>r>>a>>b>>h;
    H = h / (a-b) * a;
    a/=2; b/=2;
    cosa = H / sqrt(H*H + a*a); 
    sina = a / sqrt(H*H + a*a);
    minR = b / cosa;
    if (r<=minR) {
        cout<<"Drop"<<endl;
    } else {
        cout<<"Stuck"<<endl;
        double tmpb = r * cosa;
        double tmph = get_h(tmpb);
    
        cout<<fixed<<setprecision(10)<<h-(H-tmph)+r*sina<<endl;
    }
}