/* *** PROBLEM: 1656_c_make_equal_with_mod
ON: 2025-04-06
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (count(a.begin(), a.end(), 1) > 0) {
        sort(a.begin(), a.end());
        for (int i = 1; i < n; i++) {
            if (a[i - 1] == a[i] - 1) {
                cout << "NO" << nl;
                return;
            }
        }
        cout << "YES" << nl;
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

