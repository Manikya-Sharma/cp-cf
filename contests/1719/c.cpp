/* *** PROBLEM: 1719_c_fighting_tournament
ON: 2025-05-31
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
    int n, q;
    cin >> n >> q;
    deque<int> dq(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> dq[i];
        a[i] = dq[i];
    }
    vector<vector<int>> wins(n + 1);
    int time = 0;
    while (dq.front() != n) {
        int x = dq.front();
        dq.pop_front();
        int y = dq.front();
        dq.pop_front();
        if (x > y) {
            wins[x].push_back(time);
            dq.push_back(y);
            dq.push_front(x);
        } else {
            wins[y].push_back(time);
            dq.push_back(x);
            dq.push_front(y);
        }
        time++;
    }
    while (q--) {
        int i, k;
        cin >> i >> k;
        i = a[i - 1];
        if (k < time) {
            int ans = lower_bound(wins[i].begin(), wins[i].end(), k) -
                      wins[i].begin();
            cout << ans << nl;
        } else {
            if (i == n) {
                cout << sz(wins[i]) + k - time << nl;
            } else {
                cout << sz(wins[i]) << nl;
            }
        }
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
