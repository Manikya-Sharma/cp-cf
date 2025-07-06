/* *** PROBLEM: 1762_b_make_array_good
ON: 2025-05-21
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
    vector<pair<ll, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    vector<ll> ans(n, 0);
    for (int i = 1; i < n; i++) {
        ll prev = a[i - 1].first;
        ll curr = a[i].first;
        if (curr % prev == 0) {
            ans[a[i].second] = 0;
            continue;
        }
        ll res = prev - curr % prev;
        a[i].first += res;
        ans[a[i].second] = res;
    }
    cout << n << nl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ' ' << ans[i] << nl;
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

