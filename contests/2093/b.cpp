/* *** PROBLEM: 2093_b_expensive_number
ON: 2025-04-08
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
    ll n = sz(s);
    ll last_nz = -1;
    for (ll i = n - 1; i >= 0; i--) {
        if (s[i] != '0') {
            last_nz = i;
            break;
        }
    }
    ll cnt = 0;
    for (ll i = 0; i < last_nz; i++) {
        cnt += s[i] != '0';
    }
    cnt += n - last_nz - 1;
    cout << cnt << nl;
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

