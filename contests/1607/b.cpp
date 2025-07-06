/* *** PROBLEM: 1607_b_odd_grasshopper
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
    ll x, n;
    cin >> x >> n;
    if (x % 2 == 0) {
        if (n % 4 == 0) {
            cout << x << nl;
        } else if (n % 4 == 1) {
            cout << x - n << nl;
        } else if (n % 4 == 2) {
            cout << x + 1 << nl;
        } else {
            cout << x + n + 1 << nl;
        }
    } else {
        if (n % 4 == 0) {
            cout << x << nl;
        } else if (n % 4 == 1) {
            cout << x + n << nl;
        } else if (n % 4 == 2) {
            cout << x - 1 << nl;
        } else {
            cout << x - n - 1 << nl;
        }
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

