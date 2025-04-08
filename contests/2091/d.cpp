/* *** PROBLEM: 2091_d_place_of_the_olympiad
ON: 2025-03-25
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

bool is_possible(int r, int c, int k, int mid) {
    int benches = c / (mid + 1);
    int left = c % (mid + 1);
    ll count = benches * 1ll * mid + left;
    if (r * 1ll * count < k) {
        return false;
    }
    return true;
}

void solution_fn() {
    int r, c, k;
    cin >> r >> c >> k;

    int start = 1, end = c;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (is_possible(r, c, k, mid)) {
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

