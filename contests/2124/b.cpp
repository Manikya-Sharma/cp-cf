/* *** PROBLEM: 2124_b_minimise_sum
ON: 2025-07-06
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
    ll ans = a[0] + a[1];
    int max_t = 0;
    vector<ll> prefix(n);
    vector<bool> mins(n, false);
    prefix[0] = a[0];
    for (int i = 1; i < n; i++) {
        if (prefix[i - 1] > a[i]) {
            prefix[i] = a[i];
            mins[i] = true;
        } else {
            prefix[i] = prefix[i - 1];
        }
    }
    for (int i = 1; i < n; i++) {
        prefix[i] += prefix[i - 1];
    }
    vector<int> next_lg(n);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] <= a[i]) {
            next_lg[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    for (int i = 1; i < n; i++) {
        ll curr = prefix[i];
        if (mins[max_t]) {
            curr += a[2] * (next_lg[max_t] - max_t);
        }
        ans = min(ans, curr);
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

