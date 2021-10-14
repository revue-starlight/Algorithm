#include <cstdio>
#include <unordered_map>

using namespace std;
typedef long long LL;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,res = 0;
		LL a[2004],b[2004],c[2004],d[2004];	
		unordered_map<LL,int> ump;
		scanf("%d",&n);
		for(int i = 0; i < n; ++i)
			scanf("%lld%lld%lld%lld",a+i,b+i,c+i,d+i);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				ump[a[i]+b[j]]++;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j){
				LL tmp = c[i] + d[j];
				if(ump.count(-tmp))	res += ump[-tmp];
			}	
		printf("%d\n",res);
	}
	return 0;
}