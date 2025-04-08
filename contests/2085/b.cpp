/* *** PROBLEM: 2085_b_serval_and_final_MEX
ON: 2025-03-22
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
    vector<pair<int, int>> ans;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == 0 || a[i + 1] == 0) {
            ans.push_back({i + 1 - sz(ans), i + 2 - sz(ans)});
            i++;
        }
    }
    if (a.back() == 0 && ans.back().second != n - sz(ans) + 1) {
        ans.push_back({n - sz(ans) - 1, n - sz(ans)});
    }
    ans.push_back({1, n - sz(ans)});
    cout << sz(ans) << nl;
    for (auto& [x, y] : ans) {
        cout << x << " " << y << nl;
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
