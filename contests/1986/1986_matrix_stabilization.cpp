#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

void solution_fn() {
    int n, m;
    cin >> n >> m;
    vvi a(n, vi(m));
    vvi result(n, vi(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    if (n == 1 && m == 1) {
        cout << a[n - 1][m - 1] << nl;
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int di[4] = {-1, 1, 0, 0};
            int dj[4] = {0, 0, -1, 1};
            int nbr = 0;
            for (int k = 0; k < 4; k++) {
                int new_i = i + di[k];
                int new_j = j + dj[k];
                if (new_i >= 0 && new_j >= 0 && new_i < n && new_j < m) {
                    nbr = max(nbr, a[new_i][new_j]);
                }
            }
            result[i][j] = min(a[i][j], nbr);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << result[i][j] << " ";
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
