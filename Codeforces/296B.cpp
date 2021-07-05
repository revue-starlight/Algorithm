#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5+100;
long long SsmallT[N],SbigT[N],SeqT[N];
long long ans[N];
string s,t;
const long long mod = 1e9+7;
int main(){
    long long n;
    cin>>n>>s>>t;
    s=" "+s;
    t=" "+t;
    SsmallT[0]=SbigT[0]=SeqT[0]=1;
    for (long long i=1;i<=n;i++){
        if (s[i]!='?' && t[i]!='?'){
            if (s[i]==t[i]){
                SsmallT[i]=SsmallT[i-1];
                SbigT[i]=SbigT[i-1];
                SeqT[i]=SeqT[i-1];
                ans[i]=ans[i-1];
            } else if (s[i]>t[i]){
                SsmallT[i]=0;
                SbigT[i]=SbigT[i-1];
                SeqT[i]=0;
                ans[i]=ans[i-1]+SsmallT[i-1]-SeqT[i-1];
                ans[i]=(ans[i]+mod)%mod;
            } else if (s[i]<t[i]){
                SsmallT[i] = SsmallT[i-1];
                SeqT[i]=0;
                SbigT[i]=0;
                ans[i]=ans[i-1]+SbigT[i-1]-SeqT[i-1];
                ans[i]=(ans[i]+mod)%mod;
            }
        } else if (s[i]!='?' && t[i]=='?'){
            SsmallT[i]=SsmallT[i-1]*('9'-s[i]+1);
            SbigT[i]=SbigT[i-1]*(s[i]-'0'+1);
            SeqT[i]=SeqT[i-1];
            ans[i]=SsmallT[i-1]*(s[i]-'0')+SbigT[i-1]*('9'-s[i])-SeqT[i-1]*9+ans[i-1]*10;
            SsmallT[i] = SsmallT[i]%mod;
            SbigT[i] = SbigT[i]%mod;
            SeqT[i]=SeqT[i]%mod;
            ans[i]=(ans[i]+mod)%mod;
        } else if (s[i]=='?' && t[i]!='?'){
            SsmallT[i]=SsmallT[i-1]*(t[i]-'0'+1);
            SbigT[i]=SbigT[i-1]*('9'-t[i]+1);
            SeqT[i]=SeqT[i-1];
            ans[i]=SsmallT[i-1]*('9'-t[i])+SbigT[i-1]*(t[i]-'0')-SeqT[i-1]*9+ans[i-1]*10;
            SsmallT[i] = SsmallT[i]%mod;
            SbigT[i] = SbigT[i]%mod;
            SeqT[i]=SeqT[i]%mod;
            ans[i]=(ans[i]+mod)%mod;
        } else if (s[i]=='?' && t[i]=='?'){
            SsmallT[i]=SsmallT[i-1]*55;
            SbigT[i]=SbigT[i-1]*55;
            SeqT[i]=SeqT[i-1]*10;
            ans[i]=SsmallT[i-1]*45+SbigT[i-1]*45-SeqT[i-1]*90+ans[i-1]*100;
            SsmallT[i] = SsmallT[i]%mod;
            SbigT[i] = SbigT[i]%mod;
            SeqT[i]=SeqT[i]%mod;
            ans[i]=(ans[i]+mod)%mod;
        }
        //cout<<"I="<<i<<": "<<SsmallT[i]<<" "<<SbigT[i]<<" "<<SeqT[i]<<" "<<ans[i]<<"\n";
    }
    cout<<ans[n]<<endl;
    return 0;
}