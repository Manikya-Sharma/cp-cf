/* *** PROBLEM: 1605_b_reverse_sort
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int c0 = 0, c1 = 0;
    for (int i = 0; i < n; i++) {
        c0 += s[i] == '0';
        c1 += s[i] == '1';
    }
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') {
            if (n - i <= c1) {
                ans.push_back(i);
            }
        } else {
            if (i < c0) {
                ans.push_back(i);
            }
        }
    }
    reverse(ans.begin(), ans.end());
    if (sz(ans) == 0) {
        cout << 0 << nl;
        return;
    }
    cout << 1 << nl;
    cout << sz(ans) << ' ';
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

