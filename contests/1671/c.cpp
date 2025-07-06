/* *** PROBLEM: 1671_c_dolce_vita
ON: 2025-05-22
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
    sort(a.begin(), a.end());
    ll sum = accumulate(a.begin(), a.end(), 0ll);
    ll ans = 0;
    ll prev = -1;
    for (int i = n - 1; i >= 0; i--) {
        ll curr = (x - sum >= 0) ? (x - sum) / (i + 1) : -1;
        ans += (curr - prev) * (i + 1);
        prev = curr;
        sum -= a[i];
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
