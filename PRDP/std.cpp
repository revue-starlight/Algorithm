#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>
#include <climits>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <fstream>
#include <bitset>
#define init(a, b) memset(a, b, sizeof(a))
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define irep(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef double db;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

template <typename T> void read(T &x) {
    x = 0;
    int s = 1, c = getchar();
    for (; !isdigit(c); c = getchar())
        if (c == '-')    s = -1;
    for (; isdigit(c); c = getchar())
        x = x * 10 + c - 48;
    x *= s;
}

template <typename T> void write(T x) {
    if (x < 0)    x = -x, putchar('-');
    if (x > 9)    write(x / 10);
    putchar(x % 10 + '0');
}

template <typename T> void writeln(T x) {
    write(x);
    puts("");
}

struct Matrix {
    db v[2][2];

    Matrix() {
        init(v, 0);
    }

    friend Matrix operator * (Matrix A, Matrix B) {
        Matrix ret;
        rep(i, 0, 1)    rep(j, 0, 1)    rep(k, 0, 1)
            ret.v[i][j] += A.v[i][k] * B.v[k][j];
        return ret;
    }

    friend Matrix operator ^ (Matrix A, int k) {
        Matrix ret;
        ret.v[0][0] = ret.v[1][1] = 1;
        for (; k; k >>= 1) {
            if (k & 1)    ret = ret * A;
            A = A * A;
        }
        return ret;
    }
};

int n, pos[15];
db p;

int main() {
    while (~scanf("%d%lf", &n, &p)) {
        rep(i, 1, n)    read(pos[i]);
        sort(pos + 1, pos + 1 + n);

        pos[0] = 1, pos[n + 1] = pos[n] + 1;
        Matrix f, dp;
        f.v[0][0] = 1; 
        rep(i, 1, n + 1) {
            int t = pos[i] - pos[i - 1];
            dp.v[0][0] = p, dp.v[1][0] = 1 - p, dp.v[0][1] = 1, dp.v[1][1] = 0;
            f = f * (dp ^ t);
            if (i <= n)    f.v[0][0] = 0;
        }
        printf("%.7f\n", f.v[0][0]);
    }
    return 0;
}