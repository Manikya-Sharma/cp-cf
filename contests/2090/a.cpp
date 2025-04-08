/* *** PROBLEM: 2090_a_treasure_hunt
ON: 2025-03-23
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
    int x, y, a;
    cin >> x >> y >> a;
    ll days = a / (x + y) + (a % (x + y) != 0);
    if (days * (x + y) == a) {
        cout << "NO" << nl;
        return;
    }
    if (days * (x + y) - y > a) {
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

