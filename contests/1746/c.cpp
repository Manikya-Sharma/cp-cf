/* *** PROBLEM: 1746_c_permutation_operations
ON: 2025-08-03
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
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        pos[a[i] - 1] = i;
    }
    for (int i = 0; i < n; i++) {
        if (pos[i] == n - 1) {
            cout << 1;
        } else {
            cout << pos[i] + 2;
        }
        cout << " \n"[i == n - 1];
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

