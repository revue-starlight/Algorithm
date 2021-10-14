#include <bits/stdc++.h>
#define MAX 500
using namespace std;

string str1;
string str2;
string ans;
int Len1;
int Len2;
int Len;
int dp[MAX][MAX];
int lst[MAX][MAX];

void Getit(int len1, int len2)
{
    int i = len1, j = len2;
    if (i == 0 || j == 0)
        return;
    if (lst[i][j] == 0)
    {
        Getit(i - 1, j - 1);
        ans += str1[i - 1];
    }
    else if (lst[i][j] == 1)
        Getit(i - 1, j);
    else
        Getit(i, j - 1);
}


void solution()
{
    for (int i = 1; i <= Len1; i++)
        for (int j = 1; j <= Len2; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                lst[i][j] = 0;
            }
            else if (dp[i - 1][j] >= dp[i][j - 1])
            {
                dp[i][j] = dp[i - 1][j];
                lst[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i][j - 1];
                lst[i][j] = 2;
            }
        }
    Getit(Len1, Len2);
    cout << ans << endl;
}

void solve()
{
    Len1 = str1.length();
    Len2 = str2.length();
    Len = max(Len1, Len2);
    ans="";
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
        {
            dp[i][j] = 0;
            lst[i][j] = 0;
        }

    for (int i = 0; i <= Len; i++)
    {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }
    solution();
}


int main()
{
    cin>>str1>>str2;
    {
        solve();
    }
}