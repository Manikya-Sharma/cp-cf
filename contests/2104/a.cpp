/* *** PROBLEM: 2104_a_three_decks
ON: 2025-04-28
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
    int x = 2 * c - a - b;
    if (x % 3 != 0) {
        cout << "NO" << nl;
        return;
    }
    x /= 3;
    int t1 = c - x - a;
    int t2 = c - x - b;
    if (x < 0 || c - x - a < 0 || c - x - b < 0) {
        cout << "NO" << nl;
    } else {
        cout << "YES" << nl;
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

