/* *** PROBLEM: 2072_c_creating_keys_for_stORages_has_become_my_main_skill
ON: 2025-03-09
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
    int n, x;
    cin >> n >> x;
    int right_most = 0;
    while ((x >> right_most) & 1) {
        right_most++;
    }
    vector<int> ans;
    for (int i = 0; i < (1 << right_most); i++) {
        if (sz(ans) == n)
            break;
        ans.push_back(i);
    }
    while (sz(ans) < n) {
        ans.push_back(x);
    }
    int val = accumulate(ans.begin(), ans.end(), 0,
                         [](int u, int v) { return u | v; });
    if (val != x) {
        ans.pop_back();
        ans.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
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

