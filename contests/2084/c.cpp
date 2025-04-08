/* *** PROBLEM: 2084_c_you_soared_afar_with_grace
ON: 2025-04-06
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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    map<int, int> mp1, mp2;
    for (int i = 0; i < n; i++) {
        mp1[a[i]] = b[i];
        mp2[b[i]] = a[i];
    }
    int eq_count = 0;
    int eq_idx = -1;
    for (int i = 0; i < n; i++) {
        if (mp2[b[i]] != a[i]) {
            cout << -1 << nl;
            return;
        }
        if (a[i] == b[i]) {
            eq_count++;
            eq_idx = i;
        }
    }
    if ((n % 2 == 0 && eq_count >= 1) || (n % 2 == 1 && eq_count != 1)) {
        cout << -1 << nl;
        return;
    }
    vector<pair<int, int>> swaps;
    if (eq_count == 1 && eq_idx != n / 2) {
        swaps.push_back({eq_idx, n / 2});
        swap(a[eq_idx], a[n / 2]);
        swap(b[eq_idx], b[n / 2]);
    }
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[b[i]] = i;
    }
    for (int i = 0; i < n / 2; i++) {
        int elem = a[i];
        int curr_pos = mp[elem];
        int new_pos = n - i - 1;
        if (curr_pos == new_pos)
            continue;
        swaps.push_back({curr_pos, new_pos});
        mp[b[new_pos]] = curr_pos;
        swap(a[curr_pos], a[new_pos]);
        swap(b[curr_pos], b[new_pos]);
    }
    if (sz(swaps) > n) {
        cout << -1 << nl;
        return;
    }
    cout << sz(swaps) << nl;
    for (int i = 0; i < sz(swaps); i++) {
        auto [x, y] = swaps[i];
        cout << x + 1 << " " << y + 1 << nl;
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

