/* *** PROBLEM: 1899_d_yarik_and_musical_notes
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> f;
    for (auto& elem : a) {
        f[elem]++;
    }
    ll ans = 0;
    for (auto& [x, y] : f) {
        if (x == 1 || x == 2)
            continue;
        ans += y * 1ll * (y - 1) / 2;
    }
    ll x = f[1] + f[2];
    ans += x * (x - 1) / 2;
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

