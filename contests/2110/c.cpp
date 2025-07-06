/* *** PROBLEM: 2110_c_racing
ON: 2025-05-24
BY: Manikya
*** */

#include <bits/stdc++.h>
using namespace std;

/* *** TEMPLATE *** */

const char nl = '\n';
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
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    vector<pair<int, int>> vpi(n);
    for (int i = 0; i < n; i++) {
        cin >> vpi[i].first >> vpi[i].second;
    }
    int dl = 0, dr = 0;
    vector<int> ll(n), rr(n);
    for (int i = 0; i < n; i++) {
        auto [l, r] = vpi[i];
        if (d[i] == -1) {
            dr++;
        } else {
            dl += d[i];
            dr += d[i];
        }
        int il = max(dl, l);
        int ir = min(dr, r);
        if (il > ir) {
            cout << -1 << nl;
            return;
        }
        dl = il;
        dr = ir;
        ll[i] = dl;
        rr[i] = dr;
    }
    int h = rr[n - 1];
    for (int i = n - 1; i > 0; i--) {
        if (d[i] == -1) {
            if (h <= rr[i - 1]) {
                d[i] = 0;
            } else {
                d[i] = 1;
                h--;
            }
        } else {
            h -= d[i];
        }
    }
    if (d[0] == -1) {
        if (h <= 0)
            d[0] = 0;
        else
            d[0] = 1;
    }
    for (int i = 0; i < n; i++) {
        cout << d[i] << " \n"[i == n - 1];
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
