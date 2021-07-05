#include <bits/stdc++.h>
 
#define taskname ""
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define for0(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
 
template<class T> using v2d = vector <vector <T> >;
template<class T> bool uin(T &a, T b)
{
    return a > b ? (a = b, true) : false;
}
template<class T> bool uax(T &a, T b)
{
    return a < b ? (a = b, true) : false;
}
 
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
 
const int maxN = 2e5 + 10;
 
int n, a[maxN], ans[maxN], f[maxN * 4], g[maxN * 4], lazy[maxN * 4];
 
void build(int x, int lo, int hi)
{
    lazy[x] = 0;
    if (lo == hi)
    {
        f[x] = g[x] = lo;
        return;
    }
    int mid = (lo + hi) / 2;
    build(x * 2, lo, mid);
    build(x * 2 + 1, mid + 1, hi);
    f[x] = max(f[x * 2], f[x * 2 + 1]);
    g[x] = min(g[x * 2], g[x * 2 + 1]);
}
 
void down(int x)
{
    int t = lazy[x];
    lazy[x] = 0;
    lazy[x * 2] += t;
    lazy[x * 2 + 1] += t;
    f[x * 2] += t;
    f[x * 2 + 1] += t;
    g[x * 2] += t;
    g[x * 2 + 1] += t;
}
 
void update(int x, int lo, int hi, int L, int R)
{
    if (lo > R || hi < L)
    {
        return;
    }
    if (lo >= L && hi <= R)
    {
        f[x] -= 2;
        g[x] -= 2;
        lazy[x] -= 2;
        return;
    }
    down(x);
    int mid = (lo + hi) / 2;
    update(x * 2, lo, mid, L, R);
    update(x * 2 + 1, mid + 1, hi, L, R);
    f[x] = max(f[x * 2], f[x * 2 + 1]);
    g[x] = min(g[x * 2], g[x * 2 + 1]);
}
 
int query_f(int x, int lo, int hi, int L, int R)
{
    if (lo > R || hi < L)
    {
        return -1e9;
    }
    if (lo >= L && hi <= R)
    {
        return f[x];
    }
    down(x);
    int mid = (lo + hi) / 2;
    return max(query_f(x * 2, lo, mid, L, R), query_f(x * 2 + 1, mid + 1, hi, L, R));
}
 
int query_g(int x, int lo, int hi, int L, int R)
{
    if (lo > R || hi < L)
    {
        return 1e9;
    }
    if (lo >= L && hi <= R)
    {
        return g[x];
    }
    down(x);
    int mid = (lo + hi) / 2;
    return min(query_g(x * 2, lo, mid, L, R), query_g(x * 2 + 1, mid + 1, hi, L, R));
}
 
void solve()
{
    cin >> n;
    for1(i, n)
    {
        cin >> a[i];
    }
    vi vec(n);
    iota(all(vec), 1);
    sort(all(vec), [](int x, int y)
    {
        return a[x] < a[y];
    });
    build(1, 0, n);
    int id = 0;
    for (auto &i: vec)
    {
        while (id < (int)vec.size() && a[vec[id]] < a[i])
        {
            update(1, 0, n, vec[id], n);
            id++;
        }
        int cost = query_f(1, 0, n, i, n) - query_g(1, 0, n, 0, i - 1);
        if (cost >= 0)
        {
            uax(ans[i], cost / 2);
        }
        cost = query_f(1, 0, n, 0, i - 1) - query_g(1, 0, n, i, n);
        if (cost > 0)
        {
            uax(ans[i], (cost + 1) / 2);
        }
    }
    build(1, 0, n);
    id = 0;
    for (auto &i: vec)
    {
        while (id < (int)vec.size() && a[vec[id]] <= a[i])
        {
            update(1, 0, n, vec[id], n);
            id++;
        }
        int cost = query_f(1, 0, n, i, n) - query_g(1, 0, n, 0, i - 1);
        if (cost >= 0)
        {
            uax(ans[i], cost / 2 + 1);
        }
        cost = query_f(1, 0, n, 0, i - 1) - query_g(1, 0, n, i, n);
        if (cost > 0)
        {
            uax(ans[i], (cost - 1) / 2);
        }
    }
    for1(i, n)
    {
        cout << ans[i] << " ";
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
//    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}