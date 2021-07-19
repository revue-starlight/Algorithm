#include <bits/stdc++.h>
using namespace std;
int T;
double xx1,x2,yy1,y2,z1,z2;
double x3,x4,y3,y4,z3,z4;
double k1,k2;
const double pi = acos(-1);

double qiubing(double xx1,double yy1,double z1,double x2,double y2,double z2,double r1,double r2){
    double sum=4.00/3.00*pi*r1*r1*r1+4.00/3.00*pi*r2*r2*r2;
    double ans=0;
    double dis=sqrt((xx1-x2)*(xx1-x2)+(yy1-y2)*(yy1-y2)+(z1-z2)*(z1-z2)); //球心距离
    if(dis>=r1+r2) //没有交到的地方
    {
        ans=0;
    }
    else if (dis+r1<=r2)//重合
    {
        ans=(4.00/3.00)*pi*r1*r1*r1;
    }
    else if(dis+r2<=r1)
    {
        ans=(4.00/3.00)*pi*r2*r2*r2;
    }
    else  //相交
    {
        double cal=(r1*r1+dis*dis-r2*r2)/(2.00*dis*r1);
        double h=r1*(1-cal);
        ans+=(1.00/3.00)*pi*(3.00*r1-h)*h*h;
        cal=(r2*r2+dis*dis-r1*r1)/(2.00*dis*r2);
        h=r2*(1.00-cal);
        ans+=(1.00/3.00)*pi*(3.00*r2-h)*h*h;
    }
    return sum-ans;
}

void solve(){
    cin>>x2>>y2>>z2>>xx1>>yy1>>z1;
    cin>>x4>>y4>>z4>>x3>>y3>>z3;
    cin>>k1>>k2;
    double A1 = (2*x2-2*xx1*k1*k1)/(k1*k1-1);
    double B1 = (2*y2-2*yy1*k1*k1)/(k1*k1-1);
    double C1 = (2*z2-2*z1*k1*k1)/(k1*k1-1);
    double D1 = (k1*k1*xx1*xx1-x2*x2+k1*k1*yy1*yy1-y2*y2+k1*k1*z1*z1-z2*z2)/(k1*k1-1);
    double X1 = -A1/2;
    double Y1 = -B1/2;
    double Z1 = -C1/2;
    double R1 = sqrt((A1*A1+B1*B1+C1*C1-4*D1)/4);

    double A2 = (2*x4-2*x3*k2*k2)/(k2*k2-1);
    double B2 = (2*y4-2*y3*k2*k2)/(k2*k2-1);
    double C2 = (2*z4-2*z3*k2*k2)/(k2*k2-1);
    double D2 = (k2*k2*x3*x3-x4*x4+k2*k2*y3*y3-y4*y4+k2*k2*z3*z3-z4*z4)/(k2*k2-1);
    double X2 = -A2/2;
    double Y2 = -B2/2;
    double Z2 = -C2/2;
    double R2 = sqrt((A2*A2+B2*B2+C2*C2-4*D2)/4);
    

    double BING = qiubing(X1,Y1,Z1,X2,Y2,Z2,R1,R2);
    double v1 = R1*R1*R1*pi*4/3;
    double v2 = R2*R2*R2*pi*4/3;
    cout<<fixed<<setprecision(10)<<v1+v2-BING<<endl;
}
int main(){
    cin>>T;
    while (T--) solve();
}