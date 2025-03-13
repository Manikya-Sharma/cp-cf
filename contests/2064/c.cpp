/* ***  METADATA
PROBLEM: 2064_c_remove_the_ends
ON: 2025-02-16
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
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> acc;
    ll curr = 0;
    for (int i = 0; i < n; i++) {
        if ((a[i] > 0 && curr < 0) || (a[i] < 0 && curr > 0)) {
            acc.push_back(curr);
            curr = a[i];
        } else {
            curr += a[i];
        }
    }
    acc.push_back(curr);
    n = sz(acc);

    vector<ll> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + (acc[i - 1] < 0 ? 0 : acc[i - 1]);
    }
    vector<ll> suffix(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        suffix[i] = suffix[i + 1] + (acc[i] > 0 ? 0 : abs(acc[i]));
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, prefix[i + 1] + suffix[i]);
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
