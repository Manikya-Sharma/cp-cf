/* *** PROBLEM: 1703_e_mirror_grid
ON: 2025-07-29
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
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    int ans = 0;
    for (int r = 0; r < n / 2; r++) {
        for (int c = 0; c < n / 2; c++) {
            int one = 0;
            one += (grid[r][c] == '1');
            one += (grid[c][n - r - 1] == '1');
            one += (grid[n - r - 1][n - c - 1] == '1');
            one += (grid[n - c - 1][r] == '1');
            ans += min(one, 4 - one);
        }
    }
    if (n % 2 == 0) {
        cout << ans << nl;
        return;
    }
    for (int r = 0; r < n / 2; r++) {
        int c = n / 2;
        int one = 0;
        one += (grid[r][c] == '1');
        one += (grid[c][n - r - 1] == '1');
        one += (grid[n - r - 1][n - c - 1] == '1');
        one += (grid[n - c - 1][r] == '1');
        ans += min(one, 4 - one);
    }
    cout << ans << nl;
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

