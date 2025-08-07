/* *** PROBLEM: 2130_b_pathless
ON: 2025-07-31
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
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int sum = accumulate(a.begin(), a.end(), 0);
    if (s < sum) {
        for (int i = 0; i < n; i++) {
            cout << a[i] << " \n"[i == n - 1];
        }
        return;
    }
    if (s == sum) {
        cout << -1 << nl;
        return;
    }
    if (s == sum + 1) {
        sort(a.begin(), a.end());
        int i = 0, j = n - 1;
        while (a[i] != 1) {
            cout << a[i] << " ";
            i++;
        }
        while (a[j] != 1) {
            cout << a[j] << " ";
            j--;
        }
        while (i <= j) {
            cout << a[i] << " \n"[i == j];
            i++;
        }
        return;
    }
    cout << -1 << nl;
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
