/* *** PROBLEM: 1766_c_hamiltonian_wall
ON: 2025-08-05
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

bool move(vector<string> &grid, pair<int, int> start) {
    int n = sz(grid[0]);
    vector<vector<bool>> visited(2, vector<bool>(n, false));
    auto [r, c] = start;
    while (true) {
        if (grid[r][c] != 'B' || visited[r][c])
            break;
        visited[r][c] = true;
        if (r == 0) {
            if (grid[1][c] == 'B' && !visited[1][c]) {
                r++;
                continue;
            }
        } else {
            if (grid[0][c] == 'B' && !visited[0][c]) {
                r--;
                continue;
            }
        }
        c++;
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'B' && !visited[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void solution_fn() {
    int n;
    cin >> n;
    vector<string> grid(2);
    cin >> grid[0] >> grid[1];
    int c = 0;
    while (grid[0][c] != 'B' && grid[1][c] != 'B') {
        c++;
    }
    bool res = move(grid, {0, c}) || move(grid, {1, c});
    if (res) {
        cout << "YES" << nl;
    } else {
        cout << "NO" << nl;
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
