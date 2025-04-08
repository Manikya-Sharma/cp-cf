/* *** PROBLEM: 2075_b_array_recoloring
ON: 2025-03-17
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
    if (k == 1) {
        ll ans = a[0] + a.back();
        for (int i = 1; i < n - 1; i++) {
            ans = max(ans, a[i] + max(a[0], a.back()));
        }
        cout << ans << nl;
    } else {
        priority_queue<ll> pq;
        for (auto& elem : a) {
            pq.push(elem);
        }
        ll ans = 0;
        for (int i = 0; i < k + 1; i++) {
            ans += pq.top();
            pq.pop();
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

