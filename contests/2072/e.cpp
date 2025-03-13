/* *** PROBLEM: 2072_e_do_you_love_your_hero_and_his_two_hit_multi_target_attacks
ON: 2025-03-10
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
    int k;
    cin >> k;
    if (k == 0) {
        cout << 1 << nl;
        cout << 0 << " " << 0 << nl;
        return;
    }
    int count = 0;
    int row = 0;
    int i = -1e9, j = -1e9;
    vector<pair<int, int>> ans;
    while (count < k) {
        j++;
        if (row + count > k) {
            i++;
            ans.push_back({i, j});
            row = 1;
        } else {
            ans.push_back({i, j});
            count += row;
            row++;
        }
    }
    cout << sz(ans) << nl;
    for (auto& [x, y] : ans) {
        cout << x << " " << y << nl;
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

