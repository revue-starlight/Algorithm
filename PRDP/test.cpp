#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>
using namespace std;
struct MAT{
    double a[2][2];
    MAT(){
        memset(a,0,sizeof(a));
    }
    const MAT operator * (const MAT &rhs) const {
        MAT ret;
        for (int i=0;i<2;i++) for (int j=0;j<2;j++) ret.a[i][j]=0;
        for (int i=0;i<2;i++){
            for (int j=0;j<2;j++){
                for (int k=0;k<2;k++){
                    ret.a[i][j]+=a[i][k]*rhs.a[k][j];
                }
            }
        }
        return ret;
    }
};
int n;
double p;
int a[11];
MAT ksm(MAT a,int n){
    MAT x;
    x.a[0][0]=1; x.a[0][1]=0; 
    x.a[1][0]=0; x.a[1][1]=1;
    while (n){
        if (n%2==1){
            x=x*a;
        }
        a=a*a;
        n/=2;
    }
    return x;
}

int main(){
    
    while (~scanf("%d%lf",&n,&p)){
        MAT x;
        x.a[0][0]=p; x.a[0][1]=1-p; 
        x.a[1][0]=1; x.a[1][1]=0;
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        a[0]=1; a[n+1]=a[n]+1;
        MAT f,dp;
        f.a[0][0]=1;
        for (int i=1;i<=n+1;i++){
            int times = a[i]-a[i-1];
            MAT ret = ksm(x,times);
            f = ret * f;
            if (i <= n)    f.a[0][0] = 0;
        }
        printf("%.7f\n", f.a[0][0]);
    }
    return 0;
}