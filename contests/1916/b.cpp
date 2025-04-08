/* *** PROBLEM: 1916_b_two_divisors
ON: 2025-03-22
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

// TODO: WA
void solution_fn() {
    ll a, b;
    cin >> a >> b;
    ll g = gcd(a, b);
    ll l = a / g * b;
    if (l == b) {
        if (a == 1) {
            cout << b * b << nl;
        } else {
            cout << b * 2 << nl;
        }
    } else {
        cout << l << nl;
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

