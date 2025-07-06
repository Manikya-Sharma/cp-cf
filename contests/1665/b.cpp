/* *** PROBLEM: 1665_b_array_cloning_technique
ON: 2025-05-20
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
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
    }
    if (sz(freq) == 1) {
        cout << 0 << nl;
        return;
    }
    int max_freq = 0;
    for (auto &[_, f] : freq) {
        max_freq = max(max_freq, f);
    }
    int ans = n - max_freq;
    n -= max_freq;
    int temp = max_freq;
    while (n > 0) {
        n -= temp;
        temp *= 2;
        ans++;
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

