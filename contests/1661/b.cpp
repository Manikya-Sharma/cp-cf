/* *** PROBLEM: 1661_b_getting_zero
ON: 2025-04-11
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
    while (n--) {
        int a;
        cin >> a;
        int ans = 1e9;
        for (int i = 0; i <= 15; i++) {
            for (int j = 0; j <= 15; j++) {
                ll new_val = (a + i) * 1ll * (1 << j);
                if (new_val % 32768 == 0) {
                    ans = min(ans, i + j);
                }
            }
        }
        cout << ans << " \n"[n == 0];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
