/* *** PROBLEM: 2104_b_move_to_the_end
ON: 2025-04-28
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
    vector<long long> suff(n + 1, 0);
    vector<int> max_till(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        max_till[i] = max(max_till[i - 1], a[i - 1]);
    }
    for (int i = n - 1; i >= 0; i--) {
        suff[i] = suff[i + 1] + a[i];
    }
    vector<ll> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = max_till[i + 1] + suff[i + 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        cout << ans[i] << " \n"[i == 0];
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

