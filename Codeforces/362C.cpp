
#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
const int  N = 5e3+10;
using namespace std;
int mi[N][N],ma[N][N],num[N],cnt,ans=INT_MAX;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&num[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(num[j]>num[i]) ma[i][j]=1;
            if(num[j]<num[i]) mi[i][j]=1;
            if(j) ma[i][j]+=ma[i][j-1],mi[i][j]+=mi[i][j-1];
        }
    int cur=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        if(i<j&&num[i]>num[j]) cur++;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            if(num[i]<num[j]) continue;
            int temp=cur;
            temp+=(mi[j][j-1]-mi[j][i]+ma[i][j-1]-ma[i][i]);
            temp-=(ma[j][j-1]-ma[j][i]+mi[i][j-1]-mi[i][i]);
            temp--;
            if(ans==temp) cnt++;
            else if(ans>temp) ans=temp,cnt=1;
        }
    cout<<ans<<" "<<cnt<<endl;
    return 0;
}