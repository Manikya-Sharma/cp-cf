/* *** PROBLEM: 1617_b_gcd_problem
ON: 2025-05-19
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
    for (int i = 2; i < n - 1; i++) {
        int g = gcd(i, n - i - 1);
        if (g == 1) {
            cout << i << ' ' << n - i - 1 << ' ' << 1 << nl;
            return;
        }
    }
    assert(false);
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
