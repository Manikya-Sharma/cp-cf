/* ***  METADATA
PROBLEM: 2069_b_set_of_strangers
ON: 2025-02-20
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

#define IN_BOUND(x, y, grid)                                                   \
    x >= 0 && y >= 0 && x < int(grid.size()) && y < int(grid[0].size())

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void solution_fn() {
    int r, c;
    cin >> r >> c;
    vector<vi> grid(r, vi(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
        }
    }
    map<int, int> mp;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int cost = 1;
            for (int k = 0; k < 4; k++) {
                int new_i = i + dx[k];
                int new_j = j + dy[k];
                if (IN_BOUND(new_i, new_j, grid) &&
                    grid[new_i][new_j] == grid[i][j]) {
                    cost = 2;
                    break;
                }
            }
            mp[grid[i][j]] = max(mp[grid[i][j]], cost);
        }
    }
    ll ans = 0;
    int max_x = 0;
    for (auto& [_, x] : mp) {
        ans += x;
        max_x = max(max_x, x);
    }
    cout << ans - max_x << nl;
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
