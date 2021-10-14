#include <iostream>
using namespace std;
int a[1005][1005];
int n,m;
int main(){
	while(cin>>n>>m){		
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				a[i][j]+=max(a[i][j-1],a[i-1][j]);
			}
		}
		cout<<a[n][m]<<"\n";
	}
	
	return 0;
}