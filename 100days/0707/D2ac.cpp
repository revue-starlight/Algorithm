// Problem: D1. RPD and Rap Sheet (Easy Version)
// Contest: Codeforces - Codeforces Round #730 (Div. 2)
// URL: https://codeforces.com/contest/1543/problem/D1
// Memory Limit: 256 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
//And in that light,I find deliverance.
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int n,k;
int f(int x,int y)//减
{
	int res=0,base=1;
	while(x||y)
	{
		res+=(x%k+k-y%k)%k*base;
		base*=k;
		x/=k,y/=k;
	}
	return res;
}
int g(int x,int y)//加
{
	int res=0,base=1;
	while(x||y)
	{
		res+=(x%k+y%k)%k*base;
		base*=k;
		x/=k,y/=k;
	}
	return res;
}
signed main()
{
	for(int T=read();T--;)
	{
		n=read(),k=read();
		int s=0;
        bool t=0;
		for(int i=0; i<n; ++i)
		{
			int cur;
            if(t) cur=g(f(0,i),s);
            else cur=g(i,s);
			printf("%lld\n",cur);
			fflush(stdout);
			s=f(cur,s),t^=1;//s-cur
			if(read()==1) break;
			//如果i是0，会变成ixor s
            //printf("*%lld\n",s);
		}
	}
	return 0;
}
