#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;
double a[3],v;
double e;
void serch(double c,double m,double p,double dep,double pos){
    if (pos<1e-15) return;
    if (c<1e-15) c=0; if (m<1e-15) m=0; if (p<1e-15) p=0;
    if (c<=v && c>0){
        if (m>0)
            serch(0,m+c/2,p+c/2,dep+1,pos*c);
        if (m==0)
            serch(0,0,1,dep+1,pos*c);
    }
    if (c>v){
        if (m>0)
        serch(c-v,m+v/2,p+v/2,dep+1,pos*c);
        else
        serch(c-v,0,p+v,dep+1,pos*c);
    }
    // m
    if (m<=v && m>0){
        if (c>0)
            serch(c+m/2,0,p+m/2,dep+1,pos*m);
        if (c==0)
            serch(0,0,p+m,dep+1,pos*m);
    }
    if (m>v){
        if (c>0)
        serch(c+v/2,m-v,p+v/2,dep+1,pos*m);
        else
        serch(0,m-v,p+v,dep+1,pos*m);
    }
    // p
    p = p*pos;
    e += p*dep;
}
void solve(){
    e=0;
    for (int i=0;i<=2;i++) cin>>a[i]; cin>>v;
    serch(a[0],a[1],a[2],1,1);
    cout<<fixed<<setprecision(12)<<e<<endl;
}
signed main(){
   // freopen("a.in","r",stdin);
    cin>>T;
    while (T--) solve();
    return 0;
}