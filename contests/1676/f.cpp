/* *** PROBLEM: 1676_f_longest_strike
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> freq;
    for (auto& elem : a) {
        freq[elem]++;
    }
    vector<int> b;
    for (auto& [x, y] : freq) {
        if (y >= k) {
            b.push_back(x);
        }
    }
    if (sz(b) == 0) {
        cout << -1 << nl;
        return;
    }
    set<int> st;
    for (auto& elem : b) {
        st.insert(elem);
    }
    int ans = 0;
    int l = -1, r = -1;
    for (auto elem : a) {
        if (st.count(elem - 1))
            continue;
        int count = 0, temp = elem;
        while (st.count(temp)) {
            temp++;
            count++;
        }
        if (count > ans) {
            ans = count;
            l = elem;
            r = temp;
        }
    }
    cout << l << " " << r - 1 << nl;
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

