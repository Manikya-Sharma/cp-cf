/* *** PROBLEM: 1698_c_3_sum_closure
ON: 2025-04-13
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
    sort(a.begin(), a.end());
    vector<int> b;
    int zero_count = 0, pos_count = 0, neg_count = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] > 0) {
            if (pos_count < 2) {
                b.push_back(a[i]);
                pos_count++;
            } else {
                cout << "NO" << nl;
                return;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            if (neg_count < 2) {
                b.push_back(a[i]);
                neg_count++;
            } else {
                cout << "NO" << nl;
                return;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == 0 && zero_count < 2) {
            b.push_back(a[i]);
            zero_count++;
        }
    }
    set<int> st(b.begin(), b.end());
    for (int i = 0; i < sz(b); i++) {
        for (int j = i + 1; j < sz(b); j++) {
            for (int k = j + 1; k < sz(b); k++) {
                if (!st.count(b[i] + b[j] + b[k])) {
                    cout << "NO" << nl;
                    return;
                }
            }
        }
    }
    cout << "YES" << nl;
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

