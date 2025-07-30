/* *** PROBLEM: 2128_a_recycling_center
ON: 2025-07-27
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

// TODO: INC
void solution_fn() {
    int n, c;
    cin >> n >> c;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        ll mul = (1 << i);
        for (int j = n - 1; j >= 0; j--) {
            if (a[j] * mul > c) {
                ans++;
            }
        }
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
