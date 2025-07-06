/* *** PROBLEM: 2119_c_a_good_problem
ON: 2025-07-06
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
    ll n, l, r, k;
    cin >> n >> l >> r >> k;
    if (n == 2) {
        cout << -1 << nl;
        return;
    }
    if (n % 2 == 0) {
        int max_set = 0;
        for (int i = 0; i <= 63; i++) {
            if ((l >> i) & 1)
                max_set = i;
        }
        ll h = (1ll << (max_set + 1));
        if (h > r) {
            cout << -1 << nl;
            return;
        }
        if (k <= n - 2) {
            cout << l << nl;
        } else {
            cout << h << nl;
        }
    } else {
        cout << l << nl;
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

