/* *** PROBLEM: 2094_d_tung_tung_sahur
ON: 2025-04-15
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
    string a, b;
    cin >> a >> b;
    if (a[0] != b[0]) {
        cout << "NO" << nl;
        return;
    }
    vector<int> x, y;
    char prev = a[0];
    int cnt = 0;
    for (int i = 0; i < sz(a); i++) {
        if (a[i] == prev) {
            cnt++;
        } else {
            x.push_back(cnt);
            prev = a[i];
            cnt = 1;
        }
    }
    x.push_back(cnt);

    prev = b[0];
    cnt = 0;
    for (int i = 0; i < sz(b); i++) {
        if (b[i] == prev) {
            cnt++;
        } else {
            y.push_back(cnt);
            prev = b[i];
            cnt = 1;
        }
    }
    y.push_back(cnt);

    int i = 0, j = 0;
    while (i < sz(x) && j < sz(y)) {
        if (y[j] < x[i] || y[j] > 2 * x[i]) {
            cout << "NO" << nl;
            return;
        }
        i++;
        j++;
    }
    if (i != sz(x) || j != sz(y)) {
        cout << "NO" << nl;
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
