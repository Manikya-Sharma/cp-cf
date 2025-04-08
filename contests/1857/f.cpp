/* *** PROBLEM: 1857_f_sum_and_product
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
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        a[i] = elem * 1ll * elem;
    }
    map<ll, ll> freq;
    for (auto& elem : a) {
        freq[elem]++;
    }
    int q;
    cin >> q;
    while (q--) {
        ll x, y;
        cin >> x >> y;
        ll ss = x * 1ll * x - 2 * y;
        ll ans = 0;
        for (auto& [elem, f] : freq) {
            ll exp = ss - elem;
            if (freq.count(exp)) {
                ans += (freq[exp] - (elem == exp)) * freq[elem];
            }
        }
        cout << ans / 2 << " \n"[q == 0];
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

