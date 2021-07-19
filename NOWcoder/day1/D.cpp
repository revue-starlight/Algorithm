#include<iostream>
#include<cstring>
#define MAXN 2005
using namespace std;
int kmp[MAXN];
int la,lb,j; 
int a[MAXN][MAXN],b[MAXN];
int n,m;
int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        string s;
        cin>>s;
        for (int j=1;j<=n;j++) a[i][j]=s[j-1]-'0';
    }
    string s;
    cin>>s;
    for (int j=1;j<=m;j++) b[j]=s[j-1]-'0';
    la = n; lb = m;
    for (int i=2;i<=lb;i++)
	   {     
	   while(j&&b[i]!=b[j+1])
        j=kmp[j];    
       if(b[j+1]==b[i])j++;    
        kmp[i]=j;
       }
    j=0;
    int ans = 0;
    for (int pos = 1;pos<=n;pos++){
        j=0;
        for(int i=1;i<=la;i++)
        {
            while(j>0 &&  b[j+1]==2 && a[pos][i]==1)
            j=kmp[j];
            if  (!(b[j+1]==2 && a[pos][i]==1)) 
            j++;
            if (j==lb) {ans++; j=kmp[j];}
        }
    }
    cout<<ans<<endl;
    return 0;
}