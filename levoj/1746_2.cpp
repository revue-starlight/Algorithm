#define _for(i, x, y) for (int i = (x); i <  (y); ++i)
#define _rep(i, x, y) for (int i = (x); i <= (y); ++i)
#define _dep(i, x, y) for (int i = (x); i >= (y); --i)
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 10;

int n, m;
int a[MAXN];

void solve() {
    freopen("1.in","r",stdin);
    cin >> n;
    _for (i, 0, n) cin >> a[i];
    cin >> m;
    while (m--) {
        int x;
        cin >> x;
        auto lb = lower_bound(a, a + n, x);

        if (lb == a) {cout<<a[0]<<'\n';continue;}
        if (lb == a+n) {
            cout<<a[n-1]<<"\n";
            continue;
        }
        if (abs(*lb - x) < abs(*(lb-1) - x)) {
            cout << *lb << '\n';
        } else {
            cout<< *(lb - 1) << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _;
    // cin >> _;
    _ = 1;
    while (_--) {
        solve();
    }
    return 0;
}