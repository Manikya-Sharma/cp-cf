/* *** PROBLEM: 2078_a_final_verdict
ON: 2025-03-10
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
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        sum += elem;
    }
    if (sum % n != 0) {
        cout << "NO" << nl;
        return;
    }
    int val = sum / n;
    cout << (val == x ? "YES" : "NO") << nl;
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
