/* *** PROBLEM: 2110_b_down_with_brackets
ON: 2025-05-24
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
    int cnt = 0;
    for (int i = 0; i < sz(s); i++) {
        if (s[i] == '(') {
            cnt++;
        } else {
            cnt--;
        }
        if (cnt == 0 && i != sz(s) - 1) {
            cout << "YES" << nl;
            return;
        }
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

