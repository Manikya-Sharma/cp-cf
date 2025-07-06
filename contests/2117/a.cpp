/* *** PROBLEM: 2117_a_false_alarm
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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool enabled = false;
    bool flag = false;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!(a[i] == 0 || (enabled && a[i] == 1))) {
            if (flag) {
                cout << "NO" << nl;
                return;
            } else if (!enabled) {
                enabled = true;
            }
        }
        if (enabled)
            count++;
        if (count == x) {
            flag = true;
            enabled = false;
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

