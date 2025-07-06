/* *** PROBLEM: 2113_c_smilo_and_minecraft
ON: 2025-06-15
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

typedef enum { Gold, Empty, Obst } Cell;

void solution_fn() {
    int r, c;
    cin >> r >> c;
    int k;
    cin >> k;
    vector<vector<Cell>> grid(r, vector<Cell>(c));
    int g_count = 0;
    for (int i = 0; i < r; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < c; j++) {
            char ch = row[j];
            if (ch == 'g') {
                grid[i][j] = Gold;
                g_count++;
            } else if (ch == '.') {
                grid[i][j] = Empty;
            } else {
                grid[i][j] = Obst;
            }
        }
    }
    vector<vector<int>> prefix(r + 1, vector<int>(c + 1, 0));
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            prefix[i][j] =
                prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
            prefix[i][j] += grid[i - 1][j - 1] == Gold;
        }
    }

    int lost = g_count;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == Empty) {
                int r_low = max(0, i - k + 1);
                int r_high = min(r - 1, i + k - 1);
                int c_low = max(0, j - k + 1);
                int c_high = min(c - 1, j + k - 1);
                int cost = prefix[r_high + 1][c_high + 1] -
                           prefix[r_high + 1][c_low] -
                           prefix[r_low][c_high + 1] + prefix[r_low][c_low];
                lost = min(lost, cost);
            }
        }
    }
    cout << g_count - lost << nl;
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

