#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
const int N = 1e5;
const int p = 1e9 + 7;
using namespace std;
int n,g1[N + 5],g2[N + 5],f[N + 5],g3[N + 5];
char s[N + 5],w[N + 5];
int main()
{
    scanf("%d",&n);
    scanf("%s",s + 1);
    scanf("%s",w + 1);
    g1[0] = g2[0] = g3[0] = 1;
    for (int i = 1;i <= n;i++)
    {
        if (s[i] != '?' && w[i] != '?')
        {
            if (s[i] <= w[i])
                g1[i] = g1[i - 1];
            if (s[i] >= w[i])
                g2[i] = g2[i - 1];
            if (s[i] == w[i])
                g3[i] = g3[i - 1];
            f[i] = f[i - 1];
            if (s[i] < w[i])
                f[i] += g2[i - 1],f[i] %= p;
            if (s[i] > w[i])
                f[i] += g1[i - 1],f[i] %= p;
            if (s[i] != w[i])
                f[i] -= g3[i - 1],f[i] %= p;
        }
        if (s[i] == '?' && w[i] != '?')
        {
            f[i] = 10ll * f[i - 1] % p;
            g1[i] = 1ll * g1[i - 1] * (w[i] - '0' + 1) % p;
            g2[i] = 1ll * g2[i - 1] * (9 - (w[i] - '0') + 1) % p;
            g3[i] = g3[i - 1];
            f[i] += 1ll * g1[i - 1] * (9 - (w[i] - '0')) % p;
            f[i] %= p;
            f[i] += 1ll * g2[i - 1] * (w[i] - '0') % p;
            f[i] %= p;
            f[i] -= 9ll * g3[i - 1] % p;
            f[i] %= p;
        }
        if (s[i] != '?' && w[i] == '?')
        {
            f[i] = 10ll * f[i - 1] % p;
            g1[i] = 1ll * g1[i - 1] * (9 - (s[i] - '0') + 1) % p;
            g2[i] = 1ll * g2[i - 1] * (s[i] - '0' + 1) % p;
            g3[i] = g3[i - 1];
            f[i] += 1ll * g1[i - 1] * (s[i] - '0') % p;
            f[i] %= p;
            f[i] += 1ll * g2[i - 1] * (9 - (s[i] - '0')) % p;
            f[i] %= p;
            f[i] -= 9ll * g3[i - 1] % p;
            f[i] %= p;
        }
        if (s[i] == '?' && w[i] == '?')
        {
            f[i] = 100ll * f[i - 1] % p;
            g1[i] = 55ll * g1[i - 1] % p;
            g2[i] = 55ll * g2[i - 1] % p;
            g3[i] = 10ll * g3[i - 1] % p;
            f[i] += (45ll * g1[i - 1] % p + 45ll * g2[i - 1] % p) % p;
            f[i] %= p;
            f[i] -= 90ll * g3[i - 1] % p;
            f[i] %= p;
        }
            cout<<"I="<<i<<" "<<g1[i]<<" "<<g2[i]<<" "<<g3[i]<<" "<<f[i]<<endl;
        f[1] = 0;
    }
    cout<<(f[n] + p) % p<<endl;
    return 0;
}