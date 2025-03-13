/* *** PROBLEM: 2072_b_having_been_a_treasurer_in_the_past_i_help_goblins_deceive
ON: 2025-03-09
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
    string s;
    cin >> s;
    int dashes = 0, us = 0;
    for (auto& ch : s) {
        dashes += (ch == '-');
        us += (ch == '_');
    }
    ll ans = dashes / 2 * 1ll * (dashes / 2 + (dashes % 2 != 0)) * us;
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

