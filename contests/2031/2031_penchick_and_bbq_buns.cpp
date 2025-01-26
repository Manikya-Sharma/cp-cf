#include <bits/stdc++.h>
using namespace std;

/* *** TEMPLATE *** */

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

/* *** DEBUG *** */

#ifdef LOCAL
#include "/home/manikya/programming/c/cp/cf/utils/header.h"
#else
#define debug(...) ;
#endif

/* *** SOLUTION *** */

// TODO: Not correct
int square_root(int n) {
    int start = 1, end = n - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        ll prod = mid * 1ll * mid;
        if (prod > n) {
            end = mid - 1;
        } else if (prod < n) {
            start = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

void solution_fn() {
    int n;
    cin >> n;
    vi ans(n);
    if (n % 2 == 0) {
        int ctx = 1;
        for (int i = 0; i < n - 1; i += 2, ctx++) {
            ans[i] = ctx;
            ans[i + 1] = ctx;
        }
    } else {
        int sq = square_root(n);
        if (sq == -1) {
            cout << -1 << nl;
            return;
        } else {
            ans[0] = 1;
            ans[n - 1] = 1;
            int ctx = 2;
            for (int i = 1; i < n - 2; i += 2, ctx++) {
                ans[i] = ctx;
                ans[i + 1] = ctx;
            }
        }
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
