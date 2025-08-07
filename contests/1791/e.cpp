/* *** PROBLEM: 1791_e_negatives_and_positives
ON: 2025-08-01
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
    ll ans = 0;
    int i = 0;
    while (i < n - 1) {
        if (a[i] < 0) {
            if (a[i] + a[i + 1] < 0) {
                ans -= a[i] + a[i + 1];
            } else {
                break;
            }
        } else {
            break;
        }
        i += 2;
    }
    while (i < n) {
        ans += a[i];
        i++;
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

