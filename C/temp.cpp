#include <bits/stdc++.h>
#include <csignal>
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

#define MOD ((int)(998244353))

/* *** SOLUTION *** */

int solve(vi& a, bool prev_liar, int idx, int count,
          vector<vector<vector<int>>>& dp) {
    if (idx == sz(a)) {
        return 1;
    }
    if (dp[prev_liar][idx][count] != -1) {
        return dp[prev_liar][idx][count];
    }
    if (prev_liar) {
        if (a[idx] == count) {
            dp[prev_liar][idx][count] =
                solve(a, false, idx + 1, count, dp) % MOD;
        } else {
            dp[prev_liar][idx][count] = 0;
        }
        return dp[prev_liar][idx][count];
    } else {
        int cnt1 = solve(a, true, idx + 1, count + 1, dp) % MOD;
        int cnt2 = 0;
        if (a[idx] == count) {
            cnt2 = solve(a, false, idx + 1, count, dp) % MOD;
        }
        dp[prev_liar][idx][count] = (cnt1 + cnt2) % MOD;
        return dp[prev_liar][idx][count];
    }
}
int solveMem(vi& a) {
    int n = sz(a);
    // Create DP array with consistent dimensions
    vector<vector<vector<int>>> dp(
        2, vector<vector<int>>(n + 1, vector<int>(n / 2 + 1, 0)));

    // Set valid base cases only
    dp[0][n][0] = 1;
    dp[1][n][0] = 1;

    // Bottom-up DP
    for (int index = n - 1; index >= 0; index--) {
        for (int count = min(n / 2, index + 1); count >= 0; count--) {
            for (int prev_liar = 0; prev_liar <= 1; prev_liar++) {
                if (prev_liar) {
                    // Previous person was a liar
                    if (a[index] == count) {
                        dp[prev_liar][index][count] = dp[0][index + 1][count];
                    } else {
                        dp[prev_liar][index][count] = 0;
                    }
                } else {
                    // Previous person was truthful
                    int cnt1 = 0;
                    if (count + 1 <= n / 2) {  // Check boundary
                        cnt1 = dp[1][index + 1][count + 1];
                    }
                    int cnt2 = 0;
                    if (a[index] == count) {
                        cnt2 = dp[0][index + 1][count];
                    }
                    dp[prev_liar][index][count] =
                        ((cnt1 % MOD) + (cnt2 % MOD)) % MOD;
                }
                dp[prev_liar][index][count] %= MOD;
            }
        }
    }

    return dp[0][0][0];
}
void solution_fn() {
    int n;
    cin >> n;
    vi a(n);
    vector<vector<vector<int>>> dp(
        2, vector<vector<int>>(n + 1, vector<int>(n / 2 + 1, -1)));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // int ans = solve(a, false, 0, 0, dp) % MOD;
    int ans = solveMem(a);
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
