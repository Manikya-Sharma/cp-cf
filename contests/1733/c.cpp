/* *** PROBLEM: 1733_c_parity_shuffle_sorting
ON: 2025-04-18
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << 0 << nl;
        return;
    }
    vector<pair<int, int>> ans;
    ans.push_back({0, n - 1});
    bool odd = ((a[0] + a.back()) % 2 == 0) ? (a.back() % 2) : (a[0] % 2);
    for (int i = 1; i < n - 1; i++) {
        if (odd) {
            if (a[i] % 2 == 0) {
                ans.push_back({0, i});
            } else {
                ans.push_back({i, n - 1});
            }
        } else {
            if (a[i] % 2 == 1) {
                ans.push_back({0, i});
            } else {
                ans.push_back({i, n - 1});
            }
        }
    }
    cout << sz(ans) << nl;
    for (auto& [x, y] : ans) {
        cout << x + 1 << " " << y + 1 << nl;
    }
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

