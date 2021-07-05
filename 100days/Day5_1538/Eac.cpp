#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll a0,b0,a,b;
 
bool Check( ll x ){
	if( a0-b*x < 0 ) return false;
	ll upper = min({ (a0-b*x)/(a-b) , x });
	ll lower = max({ (a*x-b0+a-b-1)/(a-b) , 0LL });
	// P(x,lower,upper);
	return lower <= upper;
}
 
ll BinarySearch(){
	if( a == b ) return min(a0,b0) / a;
	ll l = 0, r = 1e9, ans = 0;
	while( l <= r ){
		ll mid = l+r >> 1;
		if(Check(mid)){
			// O(mid);
			ans = mid;
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	return ans;
}
 
int main(){
    int T;
    cin>>T;
	while(T--){
		cin>>a0>>b0>>a>>b;
		if( a < b ) swap(a,b);
		cout << BinarySearch() << endl;
	}
}