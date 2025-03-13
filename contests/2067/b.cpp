/* ***  METADATA
PROBLEM: 2067_b_two_large_bags
ON: 2025-02-11
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

void solution_fn() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n % 2 != 0) {
        cout << "NO" << nl;
        return;
    }
    sort(a.begin(), a.end());
    int inc = 0;
    for (int i = 0; i < n - 1; i += 2) {
        int x = max(inc, a[i]);
        int y = max(inc, a[i + 1]);
        if (x != y) {
            cout << "NO" << nl;
            return;
        }
        inc = max(inc, a[i]) + 1;
    }
    cout << "YES" << nl;
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
