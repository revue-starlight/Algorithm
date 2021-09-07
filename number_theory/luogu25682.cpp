#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e7+5;
#define ll long long
int vis[N],mu[N],tot,n;
int pri[N];
int Mobius(){
	vis[1]=mu[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i])pri[++tot]=i,mu[i]=-1;
		for(int j=1;j<=tot&&i*pri[j]<=n;j++){
			vis[i*pri[j]]=1;
			if(i%pri[j])mu[i*pri[j]]=-mu[i];
			else { mu[i*pri[j]]=0; break; }
		}
	}
	for(int i=1;i<=n;i++)
	mu[i]+=mu[i-1],vis[i]=(!vis[i])+vis[i-1];
}
inline ll calc(int a){
	ll ans=0;
	for(int i=1,j=0;i<=a;i=j+1){
		j=a/(a/i);
		ans+=1ll*(mu[j]-mu[i-1])*(a/i)*(a/i);
	}
	return ans;
}
signed main(){
	scanf("%d",&n);
	Mobius();
	ll ans=0;
	for(int i=1,j=0;i<=n;i=j+1){
		j=n/(n/i);
		ans+=1ll*(vis[j]-vis[i-1])*calc(n/i);
	}
	cout<<ans<<endl;
}