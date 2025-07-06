/* *** PROBLEM: 1666_d_deletive_editing
ON: 2025-05-20
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
    int i = sz(a) - 1, j = sz(b) - 1;
    set<char> removed;
    while (i >= 0 && j >= 0) {
        if (removed.count(b[j])) {
            cout << "NO" << nl;
            return;
        }
        if (a[i] == b[j]) {
            j--;
        } else {
            removed.insert(a[i]);
        }
        i--;
    }
    if (j < 0) {
        cout << "YES" << nl;
    } else {
        cout << "NO" << nl;
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

