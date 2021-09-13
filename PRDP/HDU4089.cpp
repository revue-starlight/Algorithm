#include <bits/stdc++.h>
using namespace std;
int T;
const int N = 2e3+100;
double f[N][N];
double c[N];
void solve(){
    int n,m,k;
    double p1,p2,p3,p4;
    while (cin>>n>>m>>k){
        cin>>p1>>p2>>p3>>p4;
        //if(p4<=0.000001){printf("0.00000\n");continue;}
    double p21 = p2/(1-p1);
    double p31 = p3/(1-p1);
    double p41 = p4/(1-p1);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=i;j++){
            if (j>k) c[j]=f[i-1][j-1]*p31;
            else c[j]=f[i-1][j-1]*p31+p41;
        }
        f[i][i]=0;
        double p = 1;
        for (int k=i;k>=1;k--){
            f[i][i]+=p*c[k];
            p*=p21;
        }
        f[i][i]/=(1-p);
        f[i][1]=p21*f[i][i]+p41;
        for (int j=2;j<i;j++){
            f[i][j]=f[i][j-1]*p21+c[j];
        }
    }
    cout<<fixed<<setprecision(5)<<f[n][m]<<"\n";
    }
}
int main(){
    { solve(); }
}
