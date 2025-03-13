/* ***  METADATA
PROBLEM: 2069_c_beautiful_sequence
ON: 2025-02-27
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

#define MOD 998244353

ll mod_exp(ll a, int b) {
    assert(b >= 0);
    if (b == 0) {
        assert(a != 0);
        return 1;
    }
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans = (ans * a) % MOD;
        }
        a = (a * 1ll * a) % MOD;
        b >>= 1;
    }
    return ans;
}

// TODO: MLE
ll solve(vi& a, int idx, bool has_3, int two_count, vector<vector<vi>>& dp) {
    if (idx < 0)
        return 0;
    if (dp[idx][has_3][two_count] != -1)
        return dp[idx][has_3][two_count];
    if (a[idx] == 1) {
        ll ans1 = solve(a, idx - 1, has_3, two_count, dp);
        ll ans2 = 0;
        if (has_3)
            ans2 = mod_exp(2, two_count) - 1;
        return (ans1 + ans2) % MOD;
    } else if (a[idx] == 2) {
        return solve(a, idx - 1, has_3, two_count + 1, dp);
    } else {
        ll ans1 = solve(a, idx - 1, has_3, two_count, dp);
        ll ans2 = 0;
        if (!has_3)
            ans2 = solve(a, idx - 1, true, 0, dp);
        return (ans1 + ans2) % MOD;
    }
}

void solution_fn() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<vector<int>>> dp(
        n + 1, vector<vector<int>>(2, vector<int>(n + 1, -1)));
    cout << solve(a, n - 1, false, 0, dp) << nl;
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
