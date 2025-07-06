/* *** PROBLEM: 1642_b_make_ap
ON: 2025-05-20
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
    int a, b, c;
    cin >> a >> b >> c;

    int new_a = b - (c - b);
    if (new_a > 0 && new_a % a == 0) {
        cout << "YES" << nl;
        return;
    }

    int new_b = a + (c - a) / 2;
    if ((c - a) % 2 == 0 && new_b > 0 && new_b % b == 0) {
        cout << "YES" << nl;
        return;
    }

    int new_c = b + b - a;
    if (new_c > 0 && new_c % c == 0) {
        cout << "YES" << nl;
        return;
    }

    cout << "NO" << nl;
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

