/* ***  METADATA
PROBLEM: 2059_b_cost_of_the_array
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

void solution_fn() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == k) {
        int curr = 1;
        for (int i = 1; i < n; i += 2) {
            if (a[i] != curr) {
                cout << curr << nl;
                return;
            }
            curr++;
        }
        cout << curr << nl;
        return;
    }
    for (int i = 1; i <= n - k + 1; i++) {
        if (a[i] != 1) {
            cout << 1 << nl;
            return;
        }
    }
    if (n == 2) {
        cout << 2 << nl;
        return;
    }
    if (a[2] == 1) {
        cout << 2 << nl;
    } else {
        cout << 1 << nl;
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
