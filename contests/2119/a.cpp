/* *** PROBLEM: 2119_a_add_or_xor
ON: 2025-07-05
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
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    if (a == b) {
        cout << 0 << nl;
        return;
    }
    if (b < a) {
        if ((a ^ 1) == b) {
            cout << y << nl;
        } else {
            cout << -1 << nl;
        }
        return;
    }
    ll cost = 0;
    if (a % 2 == 0) {
        cost += min(x, y);
        a++;
    }
    if (b % 2 == 0) {
        cost += x;
        b--;
    }
    if (x < y) {
        cost += (b - a) * x;
    } else {
        cost += (b - a) / 2 * (x + y);
    }
    cout << cost << nl;
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
