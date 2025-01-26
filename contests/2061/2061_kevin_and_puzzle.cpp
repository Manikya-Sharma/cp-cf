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

void solution_fn() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    reverse(a.begin(), a.end());
    a.push_back(0);
    reverse(a.begin(), a.end());
    vi dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        // not liar
        if (a[i] == a[i - 1]) {
            dp[i] = (dp[i] + dp[i - 1]) % MOD;
        }
        // liar
        if (i > 1 && a[i] == a[i - 2] + 1) {
            dp[i] = (dp[i] + dp[i - 2]) % MOD;
        }
    }
    cout << (dp[n - 1] + dp[n]) % MOD << nl;
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
