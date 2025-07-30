/* *** PROBLEM: 2124_c_subset_multiplication
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
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (b[i] % b[i - 1] != 0) {
            int g = gcd(b[i - 1], b[i]);
            ans = max(ans, b[i - 1] / g);
        }
    }
    for (int i = n - 1; i > 0; i--) {
        if (b[i] % b[i - 1] != 0) {
            b[i - 1] /= ans;
        }
    }
    for (int i = 1; i < n; i++) {
        if (b[i] % b[i - 1] != 0) {
            int g = gcd(b[i - 1], b[i]);
            int x = b[i - 1] / g;
            ans *= x;
        }
    }
    cout << ans << nl;
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

