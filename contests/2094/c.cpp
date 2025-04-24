/* *** PROBLEM: 2094_c_brr_brrr_patapim
ON: 2025-04-15
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
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> ans(2 * n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int pos = i + j + 1;
            ans[pos] = a[i][j];
        }
    }
    int missing = 1;
    for (int i = 1; i < 2 * n; i++) {
        missing ^= ans[i];
        missing ^= i + 1;
    }
    ans[0] = missing;
    for (int i = 0; i < 2 * n; i++) {
        cout << ans[i] << " \n"[i == 2 * n - 1];
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

