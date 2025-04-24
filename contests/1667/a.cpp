/* *** PROBLEM: 1667_a_make_it_increasing
ON: 2025-04-12
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
    ll ans = 1e18;
    for (int i = 0; i < n; i++) {
        ll score = 0;
        ll prev = 0;
        for (int j = i - 1; j >= 0; j--) {
            ll x = prev / a[j] + 1;
            score += x;
            prev = x * a[j];
        }
        prev = 0;
        for (int j = i + 1; j < n; j++) {
            ll x = prev / a[j] + 1;
            score += x;
            prev = x * a[j];
        }
        ans = min(ans, score);
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}

