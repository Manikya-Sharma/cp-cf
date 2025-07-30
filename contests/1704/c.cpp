/* *** PROBLEM: 1704_c_virus
ON: 2025-07-29
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
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> intervals;
    for (int i = 1; i < m; i++) {
        intervals.push_back(a[i] - a[i - 1] - 1);
    }
    intervals.push_back(n - (a.back() - a[0]) - 1);
    sort(intervals.begin(), intervals.end(), greater<int>());
    int ans = 0;
    int taken = 0;
    // ref: https://codeforces.com/contest/1704/submission/166355766
    for (auto &len : intervals) {
        if (len - 2 * taken <= 0)
            break;
        if (len - 2 * taken <= 2) {
            taken++;
            ans++;
        } else {
            ans += (len - 2 * taken - 1);
            taken += 2;
        }
    }
    cout << n - ans << nl;
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

