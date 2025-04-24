/* *** PROBLEM: 1901_c_add_divide_and_floor
ON: 2025-04-23
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
    sort(a.begin(), a.end());
    vector<int> ans;
    int steps = 0;
    while (a[0] != a.back()) {
        steps++;
        if (a[0] % 2 == 0) {
            a[0] = a[0] / 2;
            a.back() = a.back() / 2;
            ans.push_back(0);
        } else {
            a[0] = (a[0] + 1) / 2;
            a.back() = (a.back() + 1) / 2;
            ans.push_back(1);
        }
    }
    cout << steps << nl;
    if (steps <= n) {
        for (int i = 0; i < steps; i++) {
            cout << ans[i] << " \n"[i == steps - 1];
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

