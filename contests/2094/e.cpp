/* *** PROBLEM: 2094_e_boneca_ambalabu
ON: 2025-04-16
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
    vector<int> ones(32, 0);
    for (auto& elem : a) {
        for (int i = 0; i <= 31; i++) {
            ones[i] += ((elem >> i) & 1);
        }
    }
    ll max_ans = 0;
    for (auto& elem : a) {
        ll res = 0;
        for (int i = 0; i <= 31; i++) {
            res += (1ll << i) * (((elem >> i) & 1) ? (n - ones[i]) : ones[i]);
        }
        max_ans = max(max_ans, res);
    }
    cout << max_ans << nl;
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
