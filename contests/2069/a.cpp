/* ***  METADATA

ON: 2025-02-20
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
    n -= 2;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n - 1; i++) {
        if (a[i - 1] == 1 && a[i] == 0 && a[i + 1] == 1) {
            cout << "NO" << nl;
            return;
        }
    }
    cout << "YES" << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test_cases;
    cin >> test_cases;
#ifdef LOCAL
    int total = test_cases;
#endif
    while (test_cases--) {
#ifdef LOCAL
        cout << "******* TC " << total - test_cases << " *******" << nl;
#endif
        solution_fn();
    }
    return 0;
}
