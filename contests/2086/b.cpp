/* *** PROBLEM: 2086_b_large_array_and_segments
ON: 2025-04-03
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
    int n, k;
    ll x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll sum = accumulate(a.begin(), a.end(), 0ll);
    ll offset = x / sum;
    if (offset > k) {
        cout << 0 << nl;
        return;
    }
    x = x % sum;
    sum = 0;
    int i = n - 1;
    while (sum < x && i >= 0) {
        sum += a[i];
        i--;
    }
    ll cnt = offset * n + (n - i - 1);
    ll ans = n * 1ll * k - cnt + 1;
    cout << max(ans, 0ll) << nl;
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

