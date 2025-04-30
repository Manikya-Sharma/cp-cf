/* *** PROBLEM: 1909_c_heavy_intervals
ON: 2025-04-28
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
    vector<int> l(n), c(n);
    set<int> r;
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        r.insert(elem);
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    sort(l.rbegin(), l.rend());
    vector<int> lens;
    for (int i = 0; i < n; i++) {
        int li = l[i];
        int ri = *r.lower_bound(li);
        r.erase(ri);
        lens.push_back(ri - li);
    }
    sort(c.begin(), c.end());
    sort(lens.rbegin(), lens.rend());
    long long cost = 0;
    for (int i = 0; i < n; i++) {
        cost += lens[i] * 1ll * c[i];
    }
    cout << cost << nl;
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

