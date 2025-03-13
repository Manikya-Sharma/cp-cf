/* ***  METADATA
PROBLEM: 2062_b_clockwork
ON: 2025-01-27
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
    vector<pair<int, int>> vpi(n);
    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        vpi[i] = {elem, i};
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
        // left
        int node_val = vpi[i].first;
        int index = vpi[i].second;
        if (node_val <= 2 * index || node_val <= 2 * (n - index - 1)) {
            ok = false;
            break;
        }
    }
    if (ok) {
        cout << "YES" << nl;
    } else {
        cout << "NO" << nl;
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
