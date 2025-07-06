/* *** PROBLEM: 1681_c_double_sort
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
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<pair<int, int>> vpi;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                vpi.push_back({i, j});
                swap(a[i], a[j]);
                swap(b[i], b[j]);
            } else if (a[i] == a[j] && b[i] > b[j]) {
                vpi.push_back({i, j});
                swap(b[i], b[j]);
            }
        }
    }
    if (!is_sorted(b.begin(), b.end())) {
        cout << -1 << nl;
    } else {
        cout << sz(vpi) << nl;
        for (int i = 0; i < sz(vpi); i++) {
            cout << vpi[i].first + 1 << ' ' << vpi[i].second + 1 << nl;
        }
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

