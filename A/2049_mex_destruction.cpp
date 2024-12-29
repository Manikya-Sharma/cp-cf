#include <bits/stdc++.h>
using namespace std;

/* *** TEMPLATE *** */

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

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

    int zero_count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0)
            zero_count++;
    }
    if (zero_count == 0) {
        cout << 1 << nl;
        return;
    }
    if (zero_count == n) {
        cout << 0 << nl;
        return;
    }
    if ((zero_count == 2) && (a[0] == a[n - 1]) && (a[0] == 0)) {
        cout << 1 << nl;
        return;
    }
    if (zero_count == 1 && (a[0] == 0 || a[n - 1] == 0)) {
        cout << 1 << nl;
        return;
    }
    int breaks = a[0] == 0 ? 0 : 1;
    for (int i = 1; i < n; i++) {
        if (a[i] != 0 && a[i - 1] == 0) {
            breaks++;
        }
    }

    if (breaks == 1) {
        cout << 1 << nl;
    } else {
        cout << 2 << nl;
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
