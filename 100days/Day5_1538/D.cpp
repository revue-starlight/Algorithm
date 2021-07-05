#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int notp[N],prime[N],p_cnt;
int makePrime() {
  int p = 0;
  notp[0]=notp[1]=1;
  for (int i = 2; i <= N; ++i) {
    if (!notp[i]) 
      	prime[++p] = i;  
	for (int j = 1; j <= p && i*prime[j]<N; j ++) {
		notp[i*prime[j]]=1;
		if (i% prime[j]==0){
			break;
		}
	}
  }
  return p;
}

int getfact(int x){
	int ans = 0;
	for (int i=1;prime[i]*prime[i]<=x;i++){
		while (x%prime[i]==0){
			x/=prime[i];
			ans++;
		}
	}
	if (x>1) ans++;
	return ans;
}

int main(){
	int T;
	cin>>T;
	p_cnt = makePrime();
	
	while (T--){
		int a,b,k;
		cin>>a>>b>>k;
		int maxx = getfact(a)+getfact(b);
		if (a==b && (k==1)) cout<<"NO\n"; 
		else if (a==b) {
			int minn = 0;
			if (minn<=k && k<=maxx) cout<<"YES\n";
				else cout<<"NO\n";
		}
		if (a!=b){
			int minn;
			if (a%b==0 || b%a==0) minn=1;
			else minn = 2;
			if (minn<=k && k<=maxx) cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
}