/* *** PROBLEM: 1923_c_find_b
ON: 2025-04-22
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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> prefix(n + 1);
    vector<int> one_count(n + 1);
    prefix[0] = 0;
    one_count[0] = 0;
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + a[i - 1] - 1;
        one_count[i] = one_count[i - 1] + (a[i - 1] == 1);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;
        if (len == 1) {
            cout << "NO" << nl;
            continue;
        }
        ll sum = prefix[r] - prefix[l - 1];
        int ones = one_count[r] - one_count[l - 1];
        if (sum >= ones) {
            cout << "YES" << nl;
        } else {
            cout << "NO" << nl;
        }
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

