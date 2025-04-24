/* *** PROBLEM: 2093_e_min_max_mex
ON: 2025-04-08
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

bool is_possible(vector<int>& a, int mid, int k) {
    if (mid == 0)
        return true;
    set<int> st;
    int count = 0;
    for (auto& elem : a) {
        if (elem < mid)
            st.insert(elem);
        if (sz(st) == mid) {
            count++;
            st.clear();
        }
    }
    return count >= k;
}

void solution_fn() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int start = 0, end = n;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (is_possible(a, mid, k)) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    cout << end << nl;
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
