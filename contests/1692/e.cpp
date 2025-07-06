/* *** PROBLEM: 1692_e_binary_deque
ON: 2025-05-24
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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> mp;
    mp[0] = -1;
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (!mp.count(sum))
            mp[sum] = i;
        if (mp.count(sum - x)) {
            ans = max(ans, i - mp[sum - x]);
        }
    }
    if (ans == 0 && sum != x) {
        cout << -1 << nl;
    } else {
        cout << n - ans << nl;
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

