/* *** PROBLEM: 1904_c_array_game
ON: 2025-04-24
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
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (k >= 3) {
        cout << 0 << nl;
        return;
    }
    sort(a.begin(), a.end());
    if (k == 1) {
        ll min_val = a[1] - a[0];
        min_val = min(min_val, *min_element(a.begin(), a.end()));
        for (int i = 1; i < n; i++) {
            min_val = min(min_val, abs(a[i] - a[i - 1]));
        }
        cout << min_val << nl;
    } else {
        ll ans = LONG_LONG_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, a[i]);
            for (int j = i + 1; j < n; j++) {
                ll diff = abs(a[j] - a[i]);
                ans = min(ans, diff);
                auto lb = lower_bound(a.begin(), a.end(), diff);
                if (lb != a.end())
                    ans = min(ans, abs(*lb - diff));
                if (lb != a.begin())
                    ans = min(ans, abs(*prev(lb) - diff));
            }
        }
        cout << ans << nl;
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
