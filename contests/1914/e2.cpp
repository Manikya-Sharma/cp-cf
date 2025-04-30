/* *** PROBLEM: contests_e1_game_with_marbles
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<int> pos(n);
    iota(pos.begin(), pos.end(), 0);
    sort(pos.rbegin(), pos.rend(),
         [&](int x, int y) { return a[x] + b[x] < a[y] + b[y]; });
    ll score = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            score += a[pos[i]] - 1;
        } else {
            score -= b[pos[i]] - 1;
        }
    }
    cout << score << nl;
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
