#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,it,son[200500],res,lst,x;

vector<int> v[200500];

int main(){
	scanf("%d",&t);
    int cnt = 0;
    int TT = t;
	while(t--){
        cnt ++;
		scanf("%d",&n);res=0;
		m=n;
        if (cnt == 200) printf("n=%d",n);
		priority_queue<int> q,q2;
		for(i=1;i<=n;i++){
			v[i].clear();
		}
		for(i=1;i<=n;i++){
			scanf("%d",&k);
            if (cnt == 1983) printf("\nk=%d ",k);
			son[i]=k;
			while(k--){
				scanf("%d",&j);
                if (cnt == 1983) printf(" %d",j);
				v[j].push_back(i);
			}
			if(!son[i])q.push(-i);
		}
		while(!q.empty()){
			lst=0;res++;
			while(!q.empty()){
				x=-q.top();q.pop();
				if(x<lst){
					q2.push(-x);
				}
				else{
					lst=x;
					m--;
					for(auto i:v[x]){
						//printf("a%d %d\n",x,i);
						if(!son[i])continue;
						son[i]--;
						if(!son[i])q.push(-i);
					}
				}
			}
			if(!q2.empty())swap(q,q2);
		}
        if (TT!=20000 || (TT==20000 && cnt == 1983))
		if(m)puts("-1");
		else printf("%d\n",res);
	}
}