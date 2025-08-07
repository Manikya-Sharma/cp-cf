/* *** PROBLEM: 1711_b_party
ON: 2025-08-02
BY: Manikya
*** */

#include <bits/stdc++.h>
using namespace std;

/* *** TEMPLATE *** */

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())

/* *** DEBUG *** */

#ifdef LOCAL
#include "/home/manikya/programming/c/cp/cf/utils/header.h"
#else
#define debug(...) ;
#endif

/* *** SOLUTION *** */

void solution_fn() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<pair<int, int>> pairs(m);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        pairs[i] = {x - 1, y - 1};
    }
    if (m % 2 == 0) {
        cout << 0 << nl;
        return;
    }
    vector<int> degree(n, 0);
    for (auto &[x, y] : pairs) {
        degree[x]++;
        degree[y]++;
    }
    int ans = 1e9;
    // case 1: chain -> remove any end
    for (int i = 0; i < n; i++) {
        if (degree[i] % 2 == 1) {
            ans = min(ans, a[i]);
        }
    }
    // case 2: cycles -> remove any two adjacent nodes
    for (auto &[x, y] : pairs) {
        ans = min(ans, a[x] + a[y]);
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solution_fn();
    }
    return 0;
}
