/* *** PROBLEM: 1902_c_insert_and_equalize
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
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (a[0] == a.back()) {
        cout << sz(a) << nl;
        return;
    }
    set<int> st(a.begin(), a.end());
    int gc = a.back() - a[0];
    for (int i = 1; i < n - 1; i++) {
        gc = gcd(gc, a.back() - a[i]);
    }
    ll cost = 0;
    for (int i = 0; i < n - 1; i++) {
        cost += (a.back() - a[i]) / gc;
    }
    ll ans = cost + n;
    for (int i = 0; i < n; i++) {
        if (i == 0 || a[i - 1] != a[i] - gc) {
            ll x = a[i] - gc;
            ans = min(ans, cost + (a.back() - x) / gc);
        }
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

