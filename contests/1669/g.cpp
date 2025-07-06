/* *** PROBLEM: 1669_g_fall_down
ON: 2025-05-22
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

int find_pos(vector<int> row, int idx) {
    int i = idx + 1;
    while (i < sz(row) && row[i] != 1) {
        i++;
    }
    return i - 1;
}

void solution_fn() {
    int r, c;
    cin >> r >> c;
    vector<string> grid(r);
    for (int i = 0; i < r; i++) {
        cin >> grid[i];
    }
    vector<string> ans(r, string(c, '.'));
    for (int j = 0; j < c; j++) {
        vector<int> blocks(r, 0);
        string result(r, '.');
        for (int i = r - 1; i >= 0; i--) {
            if (grid[i][j] == '*') {
                int new_pos = find_pos(blocks, i);
                result[new_pos] = '*';
                blocks[new_pos] = 1;
            } else if (grid[i][j] == 'o') {
                blocks[i] = 1;
                result[i] = 'o';
            }
        }
        for (int i = 0; i < r; i++) {
            ans[i][j] = result[i];
        }
    }
    for (int i = 0; i < r; i++) {
        cout << ans[i] << nl;
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

