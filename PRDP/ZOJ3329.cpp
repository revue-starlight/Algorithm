#include <iostream>
#include <iomanip>
using namespace std;
const int N = 600;
struct Pii{
    double k,c;
    Pii(){k=0;c=0;}
    void init(){
        k=0;c=0;
    }
    Pii operator + (const Pii &rhs) const {
        Pii x;
        x.k = k+rhs.k;
        x.c = c+rhs.c;
        return x;
    }
    Pii operator * (const double &b) const {
        Pii x;
        x.k = k*b;
        x.c = c*b;
        return x;
    }
}cal[N];
double ans[N];
void solve(){
    int n,a,b,c;
    double k[3];
    cin>>n;for (int i=0;i<3;i++)cin>>k[i];cin>>a>>b>>c;
    for (int i=0;i<=n+40;i++) cal[i].init();
    double p = 1.0/k[0]/k[1]/k[2];
    for (int i=n;i>=0;i--){
        for (int p0=1;p0<=k[0];p0++)
            for (int p1=1;p1<=k[1];p1++)
                for (int p2=1;p2<=k[2];p2++)
                    if (p0==a&&p1==b&&p2==c)
                        cal[i].k+=p;
                    else cal[i]=cal[i]+(cal[i+p0+p1+p2]*p);
        cal[i].c+=1;
    }
    ans[0] = cal[0].c/(1-cal[0].k);
    cout<<fixed<<setprecision(10)<<ans[0]<<endl;
}
int main(){
    int T;
    cin>>T;
    while (T--) solve();
}