/* *** PROBLEM: 1713_c_build_permutation
ON: 2025-07-31
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

int get_sq(int n) {
    int start = 1, end = n;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (mid * 1ll * mid < n) {
            start = mid + 1;
        } else if (mid * 1ll * mid > n) {
            end = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

void solution_fn() {
    int n;
    cin >> n;
    vector<int> ans;
    while (n > 0) {
        if (n == 1) {
            ans.push_back(0);
            break;
        }
        int sq = -1;
        for (int i = n - 1; i <= 2 * n - 2; i++) {
            int val = get_sq(i);
            if (val != -1) {
                sq = val;
                break;
            }
        }
        // there is atleast one perfect square from n till 2 * n
        assert(sq != -1);
        int cnt = 0;
        for (int i = sq * sq - n + 1; i < n; i++) {
            ans.push_back(i);
            cnt++;
        }
        n -= cnt;
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < sz(ans); i++) {
        cout << ans[i] << " \n"[i == sz(ans) - 1];
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
