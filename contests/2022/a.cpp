/* *** PROBLEM: 2022_a_bus_to_penjamo
ON: 2025-03-29
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
    int n, r;
    cin >> n >> r;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int odd_count = 0;
    for (int i = 0; i < n; i++) {
        odd_count += a[i] % 2;
        r -= a[i] / 2;
    }
    int sad = 2 * max(0, odd_count - r);
    int ans = accumulate(a.begin(), a.end(), 0) - sad;
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

