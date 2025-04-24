/* *** PROBLEM: 1899_e_queue_sort
ON: 2025-04-22
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
    int min_elem = a[0];
    int min_idx = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < min_elem) {
            min_elem = a[i];
            min_idx = i;
        }
    }
    for (int j = min_idx + 1; j < n; j++) {
        if (a[j - 1] > a[j]) {
            cout << -1 << nl;
            return;
        }
    }
    cout << min_idx << nl;
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

