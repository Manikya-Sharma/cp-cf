/* *** PROBLEM: 1669_h_maximal_and
ON: 2025-04-12
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> unset(31);
    for (int i = 0; i <= 30; i++) {
        for (auto& elem : a) {
            if ((elem & (1 << i)) == 0) {
                unset[i]++;
            }
        }
    }
    int ans = 0;
    for (int i = 30; i >= 0; i--) {
        if (unset[i] <= k) {
            k -= unset[i];
            ans |= (1 << i);
        }
    }
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
