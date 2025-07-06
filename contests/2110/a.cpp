/* *** PROBLEM: 2110_a_fashionable_array
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if ((a[0] + a.back()) % 2 == 0) {
        cout << 0 << nl;
        return;
    }
    int op1 = 0, op2 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != a[0] % 2)
            break;
        op1++;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] % 2 != a.back() % 2)
            break;
        op2++;
    }
    cout << min(op1, op2) << nl;
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

