/* ***  METADATA
PROBLEM: 2067_e_white_magic
ON: 2025-02-12
BY: Manikya
*** */

#include <bits/stdc++.h>
using namespace std;

/* *** TEMPLATE *** */

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;

/* *** DEBUG *** */

#ifdef LOCAL
#include "/home/manikya/programming/c/cp/cf/utils/header.h"
#else
#define debug(...) ;
#endif

/* *** SOLUTION *** */

bool check(vi& a) {
    int n = sz(a);
    set<int> st;
    vector<int> min_prefix(n);
    int min_elem = 1e9;
    for (int i = 0; i < n; i++) {
        min_elem = min(min_elem, a[i]);
        min_prefix[i] = min_elem;
    }
    int mex = 0;
    for (int i = n - 1; i > 0; i--) {
        st.insert(a[i]);
        while (st.count(mex))
            mex++;
        if (min_prefix[i - 1] < mex) {
            return false;
        }
    }
    return true;
}

void solution_fn() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto left_most_zero = find(a.begin(), a.end(), 0);
    if (left_most_zero == a.end()) {
        cout << n << nl;
        return;
    }
    int idx = left_most_zero - a.begin();
    vi temp;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0 && i != idx)
            continue;
        temp.push_back(a[i]);
    }
    if (check(temp)) {
        cout << sz(temp) << nl;
    } else {
        cout << sz(temp) - 1 << nl;
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
