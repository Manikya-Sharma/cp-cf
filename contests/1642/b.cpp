/* *** PROBLEM: 1642_b_power_walking
ON: 2025-05-20
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
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            cnt++;
        }
    }
    cnt++;
    for (int i = 0; i < cnt; i++) {
        cout << cnt << ' ';
    }
    for (int j = 0; j < n - cnt; j++) {
        cout << cnt + j + 1 << ' ';
    }
    cout << nl;
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

