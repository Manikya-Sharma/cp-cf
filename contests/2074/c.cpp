/* *** PROBLEM: 2074_c_xor_and_triangle
ON: 2025-03-11
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
    int x;
    cin >> x;
    int ans = 0;
    bool f1 = false, f2 = false;
    for (int i = 0; i < 31 && (!f1 | !f2); i++) {
        if ((x >> i) & 1) {
            if (!f1) {
                ans |= (1 << i);
                f1 = true;
            }
        } else {
            if (!f2) {
                ans |= (1 << i);
                f2 = true;
            }
        }
    }
    if (ans >= x || ans == 0) {
        cout << -1 << nl;
    } else {
        cout << ans << nl;
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

