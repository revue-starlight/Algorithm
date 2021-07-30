#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;
int n, m, k;
int par[MAXN];
int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}

struct Edge {
    int u, v, c;
    bool operator<(const Edge &rhs) const {
        return c < rhs.c;
    }
};
//int ppp = 0;
Edge edge[500000 + 5];

int check(int d) {
    for (int i = 1; i <= n; ++i) par[i] = i;
    int cnt = n, i = 0;
    for (; i < m; ++i) {
        const auto &e = edge[i];
        if (e.c > d) {
            break;
        }   
        int fu = find(e.u);
        int fv = find(e.v);
        if (fu != fv) {
            --cnt;
            par[fu] = fv;
        }
    }
    return cnt;
}

void work() {
    int l = 0, r = 1e9, ans = -1, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        int tmp = check(mid);
        if (tmp == k) {
            ans = mid;
            r = mid - 1;
        } else if (tmp > k) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    if (ans == -1) { 
        cout << "-1\n";
    } else {
        cout << ans << '\n';
    }
    //cout<<ppp<<endl;
}

void solve() {
    cin >> n >> m >> k;
    // for (int i = 1; i <= n; ++i) par[i] = i;
    for (int i = 0; i < m; ++i) {
        cin >> edge[i].u >> edge[i].v >> edge[i].c;
    }

    // int cnt = n;
    // for (auto &e: edge) {
    //     int fu = find(e.u);
    //     int fv = find(e.v);
    //     if (fu == fv) continue;

    //     --cnt;
    //     par[fu] = fv;
    // }
    // if (cnt != 1) {
    //     cout  << "-1\n";
    //     return;
    // }
    sort(edge, edge + m);
    work();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}