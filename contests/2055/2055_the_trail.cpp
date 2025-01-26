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

void solution_fn() {
    int n, m;
    cin >> n >> m;
    string path;
    cin >> path;
    vector<ll> row_sum(n, 0);
    vector<ll> col_sum(m, 0);
    vector<vector<ll>> grid(n, vector<ll>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            row_sum[i] += grid[i][j];
            col_sum[j] += grid[i][j];
        }
    }
    int x = 0, y = 0;
    for (auto& dir : path) {
        if (dir == 'D') {
            grid[x][y] = -row_sum[x];
            col_sum[y] += grid[x][y];
            x++;
        } else {
            grid[x][y] = -col_sum[y];
            row_sum[x] += grid[x][y];
            y++;
        }
    }
    grid[x][y] = -col_sum.back();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j] << " ";
        }
        cout << nl;
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
