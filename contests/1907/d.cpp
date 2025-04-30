/* *** PROBLEM: 1907_d_jumping_through_segment
ON: 2025-04-27
BY: Manikya
*** */

#include <bits/stdc++.h>
using namespace std;

/* *** TEMPLATE *** */

const char nl = '\n';
typedef long long lli;
typedef long double ld;
#define sz(x) int((x).size())

/* *** DEBUG *** */

#ifdef LOCAL
#include "/home/manikya/programming/c/cp/cf/utils/header.h"
#else
#define debug(...) ;
#endif

/* *** SOLUTION *** */

bool is_possible(vector<pair<int, int>>& vpi, int k) {
    int n = sz(vpi);
    int ll = -k, rr = k;
    for (int i = 0; i < n; i++) {
        auto [l, r] = vpi[i];
        if (ll > r || rr < l) {
            return false;
        }
        ll = max(ll, l) - k;
        rr = min(rr, r) + k;
    }
    return true;
}

void solution_fn() {
    int n;
    cin >> n;
    vector<pair<int, int>> vpi(n);
    for (int i = 0; i < n; i++) {
        cin >> vpi[i].first >> vpi[i].second;
    }
    int start = 0, end = 1e9;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (is_possible(vpi, mid)) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    cout << start << nl;
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
