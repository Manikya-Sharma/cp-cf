/* *** PROBLEM: 2119_b_line_segments
ON: 2025-07-05
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
    int px, py, qx, qy;
    cin >> px >> py >> qx >> qy;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll sum = accumulate(a.begin(), a.end(), 0ll);
    ll max_len = *max_element(a.begin(), a.end());
    ll d2 = (px - qx) * 1ll * (px - qx) + (py - qy) * 1ll * (py - qy);
    if (max_len * max_len < d2) {
        if (sum * sum >= d2) {
            cout << "Yes" << nl;
        } else {
            cout << "No" << nl;
        }
    } else {
        sum -= max_len;
        max_len -= sum;
        if (max_len < 0 || max_len * max_len <= d2) {
            cout << "Yes" << nl;
        } else {
            cout << "No" << nl;
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
