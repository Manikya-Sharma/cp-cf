/* *** PROBLEM: 2123_c_prefix_min_and_suffix_max
ON: 2025-07-01
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
    vector<bool> prev_sm(n, false), next_lg(n, false);
    int temp = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > temp) {
            prev_sm[i] = true;
        }
        temp = min(temp, a[i]);
    }
    temp = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] < temp) {
            next_lg[i] = true;
        }
        temp = max(temp, a[i]);
    }
    string ans(n, '1');
    for (int i = 0; i < n; i++) {
        if (prev_sm[i] && next_lg[i])
            ans[i] = '0';
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

