/* *** PROBLEM: 2071_b_perfecto
ON: 2025-03-14
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

inline bool is_sq(ll n) {
    ll start = 1, end = n;
    while (start <= end) {
        ll mid = start + (end - start) / 2;
        if (mid > LONG_LONG_MAX / mid) {
            end = mid - 1;
            continue;
        }
        ll got = mid * mid;
        ll want = n;
        if (got > want) {
            end = mid - 1;
        } else if (got < want) {
            start = mid + 1;
        } else {
            return true;
        }
    }
    return false;
}

void solution_fn() {
    int n;
    cin >> n;
    ll sum = 0;
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (is_sq(sum + i)) {
            if (i == n) {
                cout << -1 << nl;
                return;
            }
            ans.push_back(i + 1);
            ans.push_back(i);
            sum += i;
            sum += i + 1;
            i++;
        } else {
            ans.push_back(i);
            sum += i;
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

