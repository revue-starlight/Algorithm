#include <bits/stdc++.h>
using namespace std;
int x,y,a,b;
#define int long long
int check(int n){
    if( x-b*n < 0 ) return false;
	int upper = min( (x-b*n)/(a-b) , n );
	int lower = max( (a*n-y+a-b-1)/(a-b) , 0LL );
	return lower <= upper;
}
signed main(){
    int T;
    cin>>T;
    while (T--){
        cin>>x>>y>>a>>b;
        if (a==b){
            cout<<min(x,y)/a<<endl;
            continue;
        }
        if (x<y) swap(x,y);
        if (a<b) swap(a,b);
        int l = 0, r=1e9+100;
        while (l<r){
            int mid = (l+r+1)/2;
            if (check(mid))
                l=mid;
            else r=mid-1;
        }
        
        cout<<l<<endl;
    }
    return 0;
}