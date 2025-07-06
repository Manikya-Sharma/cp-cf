/* *** PROBLEM: 2123_f_minimize_fixed_points
ON: 2025-07-05
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

// TODO: WA
void solution_fn() {
    int n;
    cin >> n;
    vector<int> sieve(n + 1, 1);
    for (int i = 2; i < n; i++) {
        if (sieve[i] != 1)
            continue;
        sieve[i] = i;
        for (int j = i; j * 1ll * i < n; j++) {
            if (sieve[j] == 1) {
                sieve[j] = i;
            }
        }
    }
    vector<int> ans(n);
    set<int> taken;
    for (int i = 0; i < n; i++) {
        int num = i + 1;
        if (sieve[num] == 1) {
            ans[i] = num;
        } else {
            int fac = num / sieve[num];
            int next = (fac + 1) * sieve[num];
            if (next > n)
                next = sieve[num];
            if (taken.count(next))
                ans[i] = num;
            else
                ans[i] = next;
        }
        taken.insert(ans[i]);
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
