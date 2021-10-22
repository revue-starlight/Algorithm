#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    int s1 = 0, s2 = 0;
    vector<int>v1, v2;
    for (int i = 1; i <= n; ++i) {
        char c; int x;
        cin >> c >> x;
        if (c == '+') s1++, v1.push_back(x);
        else s2++, v2.push_back(x);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    double ans = 0;
    for (int i = 0; i < s1; ++i) {
        ans += lower_bound(v2.begin(), v2.end(), v1[i]) - v2.begin();
    }
    ans = 1.0 * ans / s1 / s2;
    cout << fixed << setprecision(10) << ans;
}
/*
8
+ 34
+ 33
+ 26
- 34
- 38
+ 39
- 7
- 27



ard output
3
+ 2
- 3
- 1
0.5
6
+ 7
- 2
- 5
+ 4
- 2
+ 6
0.888888888888889
8
+ 34
+ 33
+ 26
- 34
- 38
+ 39
*/