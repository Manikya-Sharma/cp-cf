/* *** PROBLEM: 1613_a_long_comparision
ON: 2025-05-19
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
    int x1, p1;
    cin >> x1 >> p1;
    int x2, p2;
    cin >> x2 >> p2;

    int n1 = to_string(x1).length();
    int n2 = to_string(x2).length();

    for (int i = 0; i < n1 - n2; i++) {
        x2 *= 10;
        p2--;
    }
    for (int i = 0; i < n2 - n1; i++) {
        x1 *= 10;
        p1--;
    }

    if (p1 < p2) {
        cout << '<' << nl;
    } else if (p1 > p2) {
        cout << '>' << nl;
    } else {
        if (x1 < x2) {
            cout << '<' << nl;
        } else if (x1 > x2) {
            cout << '>' << nl;
        } else {
            cout << '=' << nl;
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
