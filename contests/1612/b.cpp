/* *** PROBLEM: 1612_b_special_permutation
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
    int n, a, b;
    cin >> n >> a >> b;
    if (a - 1 > n / 2 || n - b > n / 2) {
        cout << -1 << nl;
        return;
    }
    if (a < b && (a - 1 == n / 2 || n - b == n / 2)) {
        cout << -1 << nl;
        return;
    }
    for (int i = b + 1; i <= n; i++) {
        cout << i << ' ';
    }
    for (int i = a; i <= b; i++) {
        cout << i << ' ';
    }
    for (int i = 1; i < a; i++) {
        cout << i << ' ';
    }
    cout << nl;
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

