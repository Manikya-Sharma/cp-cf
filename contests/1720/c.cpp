/* *** PROBLEM: 1720_c_corners
ON: 2025-08-01
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

#define IN_BOUND(x, y, r, c) (x >= 0 && y >= 0 && x < r && y < c)

void solution_fn() {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> grid(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < c; j++) {
            grid[i][j] = s[j] - '0';
        }
    }
    vector<vector<pair<int, int>>> dir{{{0, -1}, {1, -1}},
                                       {{1, 0}, {1, -1}},
                                       {{0, 1}, {1, 1}},
                                       {{1, 0}, {1, 1}}};
    int one_count = 0, min_rem = 3;
    for (int x = 0; x < r; x++) {
        for (int y = 0; y < c; y++) {
            one_count += grid[x][y];
            for (auto &moves : dir) {
                int rem = grid[x][y];
                bool flag = false;
                for (auto &[dx, dy] : moves) {
                    int new_x = x + dx;
                    int new_y = y + dy;
                    if (IN_BOUND(new_x, new_y, r, c)) {
                        rem += grid[new_x][new_y];
                    } else {
                        flag = true;
                        break;
                    }
                }
                if (!flag && rem != 0)
                    min_rem = min(min_rem, rem);
            }
        }
    }
    if (one_count == 0)
        cout << 0 << nl;
    else
        cout << one_count - min_rem + 1 << nl;
}

#undef IN_BOUND

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

