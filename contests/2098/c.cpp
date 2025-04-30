/* *** PROBLEM: 2098_c_sports_bettings
ON: 2025-04-26
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
    map<int, int> mp;
    for (auto& elem : a) {
        mp[elem]++;
    }
    for (auto& [_, x] : mp) {
        if (x >= 4) {
            cout << "YES" << nl;
            return;
        }
    }
    bool s1 = false;
    int exp = 1;
    for (auto& [elem, x] : mp) {
        if (elem != exp)
            s1 = false;
        if (x > 1) {
            if (!s1) {
                s1 = true;
            } else {
                cout << "YES" << nl;
                return;
            }
        }
        exp = elem + 1;
    }

    cout << "NO" << nl;
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
