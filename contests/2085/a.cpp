/* *** PROBLEM: 2085_a_serval_and_string_theory
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

void solution_fn() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (n == 1) {
        cout << "NO" << nl;
        return;
    }
    char prev = s[0];
    bool has_diff = false;
    for (int i = 0; i < n; i++) {
        if (s[i] != prev) {
            has_diff = true;
            break;
        }
    }
    if (!has_diff) {
        cout << "NO" << nl;
        return;
    }
    string temp(s);
    reverse(temp.begin(), temp.end());
    if (s < temp) {
        cout << "YES" << nl;
    } else {
        if (k == 0) {
            cout << "NO" << nl;
        } else {
            cout << "YES" << nl;
        }
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

