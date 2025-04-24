/* *** PROBLEM: 2096_a_wonderful_sticks
ON: 2025-04-19
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
    vector<int> ans(n, 0);
    int max = 0, min = 0;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == '<') {
            ans[i] = min - 1;
            min = ans[i];
        } else {
            ans[i] = max + 1;
            max = ans[i];
        }
    }
    for (int i = 0; i < n; i++) {
        ans[i] += -min + 1;
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

