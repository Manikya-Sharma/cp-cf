/* *** PROBLEM: 2093_c_simple_repetition
ON: 2025-04-08
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

bool is_prime(int x) {
    if (x == 1)
        return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}

void solution_fn() {
    int x, k;
    cin >> x >> k;
    if (x == 1) {
        while (--k) {
            x = x * 10 + 1;
        }
        if (is_prime(x)) {
            cout << "YES" << nl;
        } else {
            cout << "NO" << nl;
        }
        return;
    }
    bool p = is_prime(x);
    if (p && k == 1) {
        cout << "YES" << nl;
    } else {
        cout << "NO" << nl;
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

