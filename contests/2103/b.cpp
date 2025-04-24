/* *** PROBLEM: 2103_b_binary_typewriter
ON: 2025-04-21
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
    string temp;
    temp.push_back(s[0]);
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            temp.push_back(s[i]);
        }
    }
    if (sz(temp) == 1) {
        cout << (temp[0] == '1') + n << nl;
        return;
    }
    if (sz(temp) == 2) {
        cout << 1 + n << nl;
        return;
    }
    if (sz(temp) == 3) {
        cout << 1 + n << nl;
        return;
    }
    if (temp[0] == '0') {
        cout << sz(temp) - 3 + n << nl;
    } else {
        cout << sz(temp) - 2 + n << nl;
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

