/* ***  METADATA
PROBLEM: 2067_c_devyatkino
ON: 2025-02-12
BY: Manikya
*** */

#include <bits/stdc++.h>
using namespace std;

/* *** TEMPLATE *** */

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;

/* *** DEBUG *** */

#ifdef LOCAL
#include "/home/manikya/programming/c/cp/cf/utils/header.h"
#else
#define debug(...) ;
#endif

/* *** SOLUTION *** */

bool is_possible(int n, int k) {
    n -= k;
    while (n) {
        int dig = n % 10;
        int steps;
        if (dig <= 7) {
            steps = 7 - dig;
        } else {
            steps = 7;
        }
        if (steps <= k)
            return true;
        n /= 10;
    }
    return false;
}

void solution_fn() {
    int n;
    cin >> n;
    for (int k = 0; k <= 9; k++) {
        if (is_possible(n, k)) {
            cout << k << nl;
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
