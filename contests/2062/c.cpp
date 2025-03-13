/* ***  METADATA
PROBLEM: 2062_c_cirno_and_operations
ON: 2025-01-28
BY: Manikya
*** */

#include <bits/stdc++.h>
using namespace std;

/* *** TEMPLATE *** */

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;

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
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll max_sum = accumulate(a.begin(), a.end(), 0ll);
    while (sz(a) > 1) {
        int x = sz(a);
        for (int i = 0; i < x - 1; i++) {
            a[i] = a[i + 1] - a[i];
        }
        ll neg_sum = 0, pos_sum = 0;
        for (int i = 0; i < x - 1; i++) {
            if (a[i] < 0) {
                neg_sum += -a[i];
            } else {
                pos_sum += a[i];
            }
        }
        if (neg_sum > pos_sum) {
            for (int i = 0; i < x - 1; i++) {
                a[i] = -a[i];
            }
        }
        a.pop_back();
        reverse(a.begin(), a.end());
        max_sum = max(max_sum, abs(pos_sum - neg_sum));
    }
    cout << max_sum << nl;
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
