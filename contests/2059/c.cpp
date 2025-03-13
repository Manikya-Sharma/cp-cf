/* ***  METADATA
PROBLEM: 2059_c_customer_service
ON: 2025-02-02
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

// TODO: how to use vector in dp?
int solve(vector<vi>& a, int idx, bitset<300>& visited,
          vector<map<bitset<300>, int>>& dp) {
    int n = sz(a);
    int exp = n - idx;
    if (idx < 0) {
        return exp;
    }
    if (dp[idx][visited] != -1)
        return dp[idx][visited];
    int max_ans = 0;
    for (int i = 0; i < n; i++) {
        if (visited.test(idx))
            continue;
        visited.set(idx);
        if (a[i][idx] == exp) {
            max_ans =
                max(exp + 1, max(max_ans, solve(a, idx - 1, visited, dp)));
        }
        visited.reset(idx);
    }
    return dp[idx][visited] = max_ans;
}

void solution_fn() {
    int n;
    cin >> n;
    vector<vi> a(n, vi(n + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
        for (int j = n - 1; j >= 0; j--) {
            a[i][j] = a[i][j + 1] + a[i][j];
        }
    }
    vector<map<bitset<300>, int>> dp(n);
    bitset<300> bt;
    bt.reset();
    cout << solve(a, n, bt, dp) << nl;
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
