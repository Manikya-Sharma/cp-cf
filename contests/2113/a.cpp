/* *** PROBLEM: 2113_a_shashlinks
ON: 2025-06-15
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

// TODO: Variant?
void solution_fn() {
    int k, a, b, x, y;
    cin >> k >> a >> b >> x >> y;
    if (x > y) {
        swap(x, y);
        swap(a, b);
    }
    int cnt1 = max(0, (k - a + x - 1) / x + ((k - a) % x == 0));
    k -= cnt1 * x;
    int cnt2 = max(0, (k - b + y - 1) / y) + ((k - b) % y == 0);
    cout << cnt1 + cnt2 << nl;
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

