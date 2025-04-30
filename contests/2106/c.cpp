/* *** PROBLEM: 2106_c_cherry_bomb
ON: 2025-04-25
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
    vector<int> b(n);
    int ss = -1;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (b[i] != -1)
            ss = a[i] + b[i];
    }
    if (ss != -1) {
        for (int i = 0; i < n; i++) {
            if (b[i] != -1 && a[i] + b[i] != ss) {
                cout << 0 << nl;
                return;
            }
            int exp = ss - a[i];
            if (exp < 0 || exp > k) {
                cout << 0 << nl;
                return;
            }
        }
        cout << 1 << nl;
        return;
    }
    int max_val = *max_element(a.begin(), a.end());
    int min_val = *min_element(a.begin(), a.end());
    int lb = max_val;
    int ub = k + min_val;
    cout << ub - lb + 1 << nl;
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

