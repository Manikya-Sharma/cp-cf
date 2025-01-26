#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;

void solution_fn() {
    int n;
    cin >> n;
    vector<vector<int>> grid(2, vector<int>(n, 0));
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < n; i++) {
            char elem;
            cin >> elem;
            if (elem == 'x')
                grid[j][i] = 1;
        }
    }

    int cells = 0;
    for (int i = 1; i < n - 1; i++) {
        if (grid[0][i - 1] == 1 && grid[0][i] == 0 && grid[0][i + 1] == 1 &&
            grid[1][i - 1] == 0 && grid[1][i] == 0 && grid[1][i + 1] == 0)
            cells++;
        else if (grid[0][i - 1] == 0 && grid[0][i] == 0 &&
                 grid[0][i + 1] == 0 && grid[1][i - 1] == 1 &&
                 grid[1][i] == 0 && grid[1][i + 1] == 1)
            cells++;
    }
    cout << cells << nl;
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
