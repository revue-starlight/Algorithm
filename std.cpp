#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1000005;
int buf[MAXN];
int sa[MAXN];
int rnk[MAXN];
int tmp[MAXN];
int lcp[MAXN];
int len,k;
int t;

bool comp(int i,int j)
{
    if(rnk[i]!=rnk[j])    return rnk[i]<rnk[j];
    else
    {
        int ri=(i+k<=len)?rnk[i+k]:-1;
        int rj=(j+k<=len)?rnk[j+k]:-1;
        return ri<rj;
    }
}

void getsa()
{
    memset(sa,0,sizeof(sa));
    memset(rnk,0,sizeof(rnk));
    memset(tmp,0,sizeof(tmp));
    
    for(int i=0;i<len;i++)
    {
        sa[i]=i;
        rnk[i]=buf[i];
    }
    sa[len]=len;
    rnk[len]=-1;
    
    for(k=1;k<=len;k*=2)
    {
        sort(sa,sa+len+1,comp);
        
        tmp[sa[0]]=0;
        for(int i=1;i<=len;i++)
        {
            tmp[sa[i]]=tmp[sa[i-1]]+(comp(sa[i-1],sa[i])?1:0);
        }
        
        for(int i=0;i<=len;i++)
        {
            rnk[i]=tmp[i];    
        }
    }
    
}

void getlcp()
{
    getsa();
    memset(rnk,0,sizeof(rnk));
    memset(lcp,0,sizeof(lcp));
    for(int i=0;i<=len;i++)
    {
        rnk[sa[i]]=i;
    }
    
    int h=0;
    lcp[0]=h;
    for(int i=0;i<len;i++)
    {
        int j=sa[rnk[i]-1];
        if(h>0)    h--;
        for(;i+h<len&&j+h<len;h++)
        {
            if(buf[i+h]!=buf[j+h])    break;
        }
        lcp[rnk[i]-1]=h;
    }
    
}

void debug()
{
    for(int i=0;i<=len;i++)
    {
        int l=sa[i];
        if(l==len)
        {
            printf("0\n");
        }
        else
        {
            for(int j=sa[i];j<len;j++)
            {
                printf("%d ",buf[j]);
            }    
            printf("     %d\n",lcp[i]);
        }
    }
    
}

bool judge(int l)
{
    int  cnt=0;
    for(int i=1;i<len;i++)
    {
        if(lcp[i]>=l)//求前缀大于等于l的连续长度 
        {
            cnt++;
        }
        else
            cnt=0;
        if(cnt==t-1)    return true;
    }
    return false;
}

void solve()
{
    
    int l=1,r=len;
    int ans=0;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(judge(mid))//2分枚举长度 
        {
            ans=max(ans,mid);
            l=mid+1;
        }
        else    r=mid-1;
    }
    printf("%d\n",ans);
}

int main()
{
    while(scanf("%d%d",&len,&t)!=EOF)
    {
        for(int i=0;i<len;i++)
            scanf("%d",&buf[i]);
        getlcp();
    //    debug()
        solve();
    }
    return 0;
}