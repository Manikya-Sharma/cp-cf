/* *** PROBLEM: 1753_a1_make_nonzero_sum_(easy_version)
ON: 2025-08-05
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
    if (accumulate(a.begin(), a.end(), 0) % 2 != 0) {
        cout << -1 << nl;
        return;
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n - 1; i += 2) {
        if (a[i] == a[i + 1]) {
            ans.push_back({i + 1, i + 2});
        } else {
            ans.push_back({i + 1, i + 1});
            ans.push_back({i + 2, i + 2});
        }
    }
    cout << sz(ans) << nl;
    for (auto &[l, r] : ans) {
        cout << l << " " << r << nl;
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

