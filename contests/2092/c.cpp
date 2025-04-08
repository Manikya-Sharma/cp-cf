/* *** PROBLEM: 2092_c_asuna_and_the_mosquitos
ON: 2025-03-29
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
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool has_diff = false;
    for (int i = 0; i < n; i++) {
        if ((a[i] % 2) != (a[0] % 2)) {
            has_diff = true;
            break;
        }
    }
    if (!has_diff) {
        cout << *max_element(a.begin(), a.end()) << nl;
        return;
    }
    ll sum = 0;
    int odd_elems = 0;
    for (auto& elem : a) {
        sum += elem;
        odd_elems += elem % 2 == 1;
    }
    cout << sum - odd_elems + 1 << nl;
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
