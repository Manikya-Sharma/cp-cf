/* *** PROBLEM: 2075_c_two_colors
ON: 2025-03-17
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

int bs(vector<int>& a, int ub, int start) {
    int end = sz(a) - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (a[mid] < ub) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return start;
}

void solution_fn() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int idx = 0, j = 1;
    ll ans = 0;
    while (j < n) {
        while (idx < m && a[idx] < j) {
            idx++;
        }
        if (idx == m)
            break;
        int x = bs(a, n - j, idx + 1);
        int left = x - idx;
        ll right = m - x;
        ans += right * left;
        ans += right * (right - 1) / 2;
        j++;
    }
    cout << 2 * ans << nl;
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
