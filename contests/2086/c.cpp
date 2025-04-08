/* *** PROBLEM: 2086_c_disappearing_permutation
ON: 2025-04-03
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
    set<int> misplaced;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        if (a[i] != i + 1) {
            misplaced.insert(a[i]);
        }
        mp[a[i]] = i + 1;
    }
    int cost = 0;
    for (int q = 0; q < n; q++) {
        int d;
        cin >> d;
        while (misplaced.count(d)) {
            cost++;
            misplaced.erase(d);
            d = mp[d];
        }
        cost += d == mp[d];
        cout << cost << " \n"[q == n - 1];
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

