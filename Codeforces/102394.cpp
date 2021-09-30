#define _for(i, x, y) for (int i = (x); i <  (y); ++i)
#define _rep(i, x, y) for (int i = (x); i <= (y); ++i)
#define _dep(i, x, y) for (int i = (x); i >= (y); --i)
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAXN = 1e5;
typedef long long ll;
int n;

struct Seq {
    ll type, rem, sz;
    int x, y;
    Seq():type(-1), rem(0), sz(0), x(-1), y(-1) {}
};
vector<int> qa[1000000 + 1];

void solve() {
    cin >> n;
    
    vector<Seq> seqs(n+1);
    _rep (i, 1, n) {
        int format;
        cin >> format;
        if (format == 1) {
            cin >> seqs[i].sz;
            qa[i].resize(seqs[i].sz);
            ll which = -1, occ = 0;
            _for (j, 0, seqs[i].sz) {
                cin >> qa[i][j];
                if (qa[i][j] == which) {
                    ++occ;
                } else {
                    if (occ == 0) {
                        occ = 1;
                        which = qa[i][j];
                    } else {
                        --occ;
                        if (occ <= 0) which = -1;
                    }
                }
            }
            seqs[i].type = which;
            seqs[i].rem = 0;
            for (auto x: qa[i]) seqs[i].rem += (x == which);
        } else {
            qa[i].clear();
            cin >> seqs[i].x >> seqs[i].y;
            auto lhs = &seqs[seqs[i].x], rhs = &seqs[seqs[i].y];
            seqs[i].sz = lhs->sz + rhs->sz;
            if (lhs->type == rhs->type) {
                seqs[i].type = lhs->type;
                seqs[i].rem = lhs->rem + rhs->rem;
            } else {
                if (lhs->rem > rhs->rem) {
                    seqs[i].type = lhs->type;
                    seqs[i].rem = lhs->rem - rhs->rem;
                } else {
                    seqs[i].type = rhs->type;
                    seqs[i].rem = rhs->rem - lhs->rem;
                    if (seqs[i].rem <= 0) {
                        seqs[i].type = -1;
                    }
                }
            }
        }
    }

    if (seqs[n].type == -1) {
        cout << seqs[n].sz << '\n';
    } else {
        _rep (i, 1, n) {
            if (qa[i].empty()) {
                auto lhs = &seqs[seqs[i].x], rhs = &seqs[seqs[i].y];
                seqs[i].rem = lhs->rem + rhs->rem;
            } else {
                seqs[i].rem = 0;
                for (auto x: qa[i]) seqs[i].rem += (x == seqs[n].type);
            }
        }
        ll cnt = seqs[n].rem;
        if (2 * cnt >= seqs[n].sz) {
            cout << (seqs[n].sz - cnt) * 2 << '\n';
        } else {
            cout << seqs[n].sz << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _;
    cin >> _;
    // _ = 1;
    while (_--) {
        solve();
    }
    return 0;
}