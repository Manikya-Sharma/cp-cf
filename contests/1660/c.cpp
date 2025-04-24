/* *** PROBLEM: 1660_c_get_an_even_string
ON: 2025-04-11
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
    string s;
    cin >> s;
    int n = sz(s);

    vector<ll> prev(27, INT_MIN);
    prev[26] = 0;
    for (int i = 0; i < n; i++) {
        vector<ll> curr(27);
        for (int j = 0; j <= 26; j++) {
            ll res = prev[j];
            if (j == 26) {
                res = max(res, 1 + prev[s[i] - 'a']);
            }
            if (j + 'a' == s[i]) {
                res = max(res, 1 + prev[26]);
            }
            curr[j] = res;
        }
        prev = curr;
    }

    ll ans = prev[26];
    cout << sz(s) - ans << nl;
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

