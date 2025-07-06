/* *** PROBLEM: 1674_d_a_b_c_sort
ON: 2025-05-23
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
    vector<int> ans;
    for (int i = n - 1; i > 0; i -= 2) {
        ans.push_back(max(a[i], a[i - 1]));
        ans.push_back(min(a[i], a[i - 1]));
    }
    if (n % 2 == 1) {
        ans.push_back(a[0]);
    }
    reverse(ans.begin(), ans.end());
    if (is_sorted(ans.begin(), ans.end())) {
        cout << "YES" << nl;
    } else {
        cout << "NO" << nl;
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

