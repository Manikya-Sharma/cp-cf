/* *** PROBLEM: 2078_c_breach_of_faith
ON: 2025-03-11
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
    vector<int> b(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    cout << b[0] << ' ';
    int i = 1, j = 2 * n - 2;
    ll sum = 0;
    while (i < j) {
        cout << b[i] << ' ' << b[j] << ' ';
        sum += b[i] - b[j];
        i++;
        j--;
    }
    cout << b[0] + b.back() - sum << ' ';
    cout << b.back() << nl;
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

