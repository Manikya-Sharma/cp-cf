/* ***  METADATA
PROBLEM: 2064_d_eating
ON: 2025-02-16
BY: Manikya
*** */

#include <bits/stdc++.h>
using namespace std;

/* *** TEMPLATE *** */

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;

/* *** DEBUG *** */

#ifdef LOCAL
#include "/home/manikya/programming/c/cp/cf/utils/header.h"
#else
#define debug(...) ;
#endif

/* *** SOLUTION *** */

// TODO: WA
int solve(vi& a, vi& suff, int x) {
    int n = sz(a);
    int start = 0, end = n - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if ((x ^ suff[mid]) >= a[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return start;
}

void solution_fn() {
    int n, q;
    cin >> n >> q;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vi suff(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        suff[i] = suff[i + 1] ^ a[i];
    }
    debug(a, suff);
    while (q--) {
        int x;
        cin >> x;
        int res = solve(a, suff, x);
        cout << res << " \n"[q == 0];
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
