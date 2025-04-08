/* *** PROBLEM: 2028_a_alice_adventures_in_chess
ON: 2025-03-21
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
    int n, qx, qy;
    cin >> n >> qx >> qy;
    string s;
    cin >> s;
    int x = 0, y = 0;
    vector<pair<int, int>> reachable;
    reachable.push_back({0, 0});
    for (int i = 0; i < n; i++) {
        char dir = s[i];
        if (dir == 'N') {
            y++;
        } else if (dir == 'E') {
            x++;
        } else if (dir == 'S') {
            y--;
        } else {
            x--;
        }
        if (x == qx && y == qy) {
            cout << "YES" << nl;
            return;
        }
        reachable.push_back({x, y});
    }
    for (auto& [px, py] : reachable) {
        for (int k = 1; k <= 100; k++) {
            if (px + k * x == qx && py + k * y == qy) {
                cout << "YES" << nl;
                return;
            }
        }
    }
    cout << "NO" << nl;
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

