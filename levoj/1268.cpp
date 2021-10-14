#include <bits/stdc++.h>
using namespace std;
int m[10001];
int main()
{
    int n;
    int tot = 0;
    int ans = numeric_limits<int>::min();
	while(cin>>n)
	{
        int minn = numeric_limits<int>::max();
        int maxx = numeric_limits<int>::min();
		for(int i = 0; i < n; i++)
		{
            int xx;
            cin>>xx;
            tot+=xx;
            minn = min(minn,tot);
            ans = max(ans,tot-minn);
		}
		
        cout<<ans<<"\n";
	}
    
	return 0;
}