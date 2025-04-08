/* *** PROBLEM: 2065_d_skibidus_and_sigma
ON: 2025-03-22
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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> sa(n);
    for (int i = 0; i < n; i++) {
        ll simple_sum = 0;
        ll sum = 0;
        for (int j = 0; j < m; j++) {
            ll elem;
            cin >> elem;
            sum += elem * (m - j);
            simple_sum += elem;
        }
        a[i] = sum;
        sa[i] = simple_sum;
    }
    priority_queue<pair<ll, ll>> pq;
    for (int i = 0; i < n; i++) {
        pq.push({sa[i] * m, a[i]});
    }
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        auto [y, x] = pq.top();
        pq.pop();
        sum += x + y * (n - i - 1);
    }
    cout << sum << nl;
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

