#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int maxn = 1e5+5;
 
char s[maxn],t[maxn];
int diff[maxn],chag[maxn];
 
int main()
{
    freopen("data.in","r",stdin);
    freopen("std.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        //freopen(".txt","r",stdin);
        //ios::sync_with_stdio(false);
        //cin.tie(0);
        scanf("%s%s",s,t);
        diff[n] = 0;
        diff[n+1] = 0;
        for(int i=n-1;i>=0;i--)
        {
            diff[i] = diff[i+1];
            if(s[i]!=t[i])
                diff[i]++;
        }
        t[n] = '0';
        s[n] = '0';
        chag[0] = 0;
        if(s[0]=='0')
            chag[0]++;
        if(t[0]=='1')
            chag[0]++;
        /*if(t[1]=='0')
            chag[0]++;
        */
        for(int i=1;i<n;i++)
        {
            chag[i] = chag[i-1];
            if(s[i]=='0')
                chag[i]++;
            if(t[i]=='1')
                chag[i]++;
            /*else
                chag[i]--;
            if(t[i+1]=='0')
                chag[i]++;*/
        }
        int re = diff[0];
        for(int i=0;i<n;i++)
        {
            /*if(s[i+1]=='1')
                continue;*/
            int now = chag[i] + diff[i+2] + 1;
            if(t[i+1]=='0')
                now++;
            if(s[i+1]=='1')
                now++;
            re = re>now?now:re;
        }
        //re = re>chag[n-1]?chag[n-1]:re;
        printf("%d\n",re);
        /*for(int i=0;i<n;i++)
            cout << diff[i];
        cout << endl;
        for(int i=0;i<n;i++)
            cout << chag[i];
        cout << endl;*/
    }
    return 0;
}