/* *** PROBLEM: 2117_d_retaliation
ON: 2025-06-08
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
    if (n == 1) {
        cout << "YES" << nl;
        return;
    }
    if ((2 * a[0] - a[1]) % (n + 1) != 0) {
        cout << "NO" << nl;
        return;
    }
    int y = (2 * a[0] - a[1]) / (n + 1);
    int x = a[0] - y * n;
    if (x < 0 || y < 0) {
        cout << "NO" << nl;
        return;
    }
    for (int i = 3; i <= n; i++) {
        if (a[i - 1] - x * i - y * (n - i + 1) != 0) {
            cout << "NO" << nl;
            return;
        }
    }
    cout << "YES" << nl;
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

