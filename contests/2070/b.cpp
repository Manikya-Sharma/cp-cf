/* *** PROBLEM: 2070_b_robot_program
ON: 2025-03-13
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
    int n, x;
    cin >> n >> x;
    ll k;
    cin >> k;
    string s;
    cin >> s;

    int i;
    for (i = 0; i < n; i++) {
        if (s[i] == 'L') {
            x--;
        } else {
            x++;
        }
        if (x == 0) {
            break;
        }
    }
    if (x != 0) {
        cout << 0 << nl;
        return;
    }
    k -= i + 1;
    i = -1;
    for (int j = 0; j < n; j++) {
        if (s[j] == 'L') {
            x--;
        } else {
            x++;
        }
        if (x == 0) {
            i = j;
            break;
        }
    }
    if (i == -1) {
        cout << 1 << nl;
        return;
    }
    cout << k / (i + 1) + 1 << nl;
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

