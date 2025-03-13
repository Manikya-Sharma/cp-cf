/* *** PROBLEM: 2078_b_vicious_labyrinth
ON: 2025-03-10
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
    int n, k;
    cin >> n >> k;
    if (k % 2 == 0) {
        for (int i = 0; i < n - 2; i++) {
            cout << n - 1 << ' ';
        }
        cout << n << ' ' << n - 1 << nl;
    } else {
        for (int i = 0; i < n - 1; i++) {
            cout << n << ' ';
        }
        cout << n - 1 << nl;
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

