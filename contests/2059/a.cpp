/* ***  METADATA
PROBLEM: 2059_a_milya_and_two_arrays
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
    int n;
    cin >> n;
    set<int> a, b;
    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        a.insert(elem);
    }
    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        b.insert(elem);
    }
    if (sz(a) <= 1 && sz(b) <= 1) {
        cout << "NO" << nl;
        return;
    }
    if (sz(a) == 1) {
        if (sz(b) >= 3) {
            cout << "YES" << nl;
        } else {
            cout << "NO" << nl;
        }
        return;
    }
    if (sz(b) == 1) {
        if (sz(a) >= 3) {
            cout << "YES" << nl;
        } else {
            cout << "NO" << nl;
        }
        return;
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
