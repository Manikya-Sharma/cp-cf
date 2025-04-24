/* *** PROBLEM: 1693_a_directional_increase
ON: 2025-04-13
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
    vector<ll> a(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + a[i];
    }
    if (a.back() != 0) {
        cout << "NO" << nl;
        return;
    }
    bool flag = false;
    for (int i = 0; i <= n; i++) {
        if (flag) {
            if (a[i] != 0) {
                cout << "NO" << nl;
                return;
            }
        }
        if (a[i] < 0) {
            cout << "NO" << nl;
            return;
        } else if (a[i] == 0) {
            flag = true;
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
