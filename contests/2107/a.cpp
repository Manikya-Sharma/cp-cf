/* *** PROBLEM: 2107_a_lrc_and_vip
ON: 2025-05-18
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
    int prev = a[0];
    bool uniq = false;
    for (int i = 1; i < n; i++) {
        if (a[i] != prev) {
            uniq = true;
            break;
        }
    }
    if (!uniq) {
        cout << "NO" << nl;
    } else {
        cout << "YES" << nl;
        auto idx = max_element(a.begin(), a.end());
        for (int i = 1; i <= n; i++) {
            cout << (idx == a.begin() + i - 1) + 1 << " \n"[i == n];
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

