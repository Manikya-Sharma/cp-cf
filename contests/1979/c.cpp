/* *** PROBLEM: 1979_c_earning_on_bets
ON: 2025-04-29
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

ll lcm(vector<int>& arr, int start) {
    int n = sz(arr);
    if (start == n - 1)
        return arr[start];
    return lcm(arr[start], lcm(arr, start + 1));
}

void solution_fn() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll l = lcm(a, 0);
    vector<ll> ans;
    for (int i = 0; i < n; i++) {
        ans.push_back(l / a[i]);
    }
    if (accumulate(ans.begin(), ans.end(), 0ll) >= l) {
        cout << -1 << nl;
        return;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
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

