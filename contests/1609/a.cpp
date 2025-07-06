/* *** PROBLEM: 1609_a_divide_and_multiply
ON: 2025-05-19
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> freq(n, 0);
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (a[i] % (1 << j) == 0) {
            j++;
        }
        freq[i] = j - 1;
    }
    ll sum = accumulate(a.begin(), a.end(), 0ll);
    int fsum = accumulate(freq.begin(), freq.end(), 0);
    ll loss = 0;
    for (int i = 0; i < n; i++) {
        loss += a[i] - a[i] / (1 << freq[i]);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int mtimes = fsum - freq[i];
        ll mloss = loss - (a[i] - a[i] / (1ll << freq[i]));
        ll mgain = a[i] * ((1ll << mtimes) - 1);
        ans = max(ans, sum + mgain - mloss);
    }
    cout << ans << nl;
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

