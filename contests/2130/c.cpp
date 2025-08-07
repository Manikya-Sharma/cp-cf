/* *** PROBLEM: 2130_c_double_perspective
ON: 2025-08-01
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
    vector<pair<int, int>> vpi(n);
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> vpi[i].first >> vpi[i].second;
        mp[vpi[i]] = i;
    }
    sort(vpi.begin(), vpi.end());
    pair<int, int> prev = vpi[0];
    vector<int> ans = {mp[vpi[0]]};
    for (int i = 1; i < n; i++) {
        auto [cx, cy] = vpi[i];
        auto [px, py] = prev;
        if (cx <= py) {
            if (cy > py) {
                prev.second = cy;
                ans.push_back(mp[vpi[i]]);
            }
        } else {
            ans.push_back(mp[vpi[i]]);
            prev = vpi[i];
        }
    }
    cout << sz(ans) << nl;
    for (int i = 0; i < sz(ans); i++) {
        cout << ans[i] + 1 << " \n"[i == sz(ans) - 1];
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

