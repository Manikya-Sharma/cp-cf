#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

void solution_fn() {
    int x, y, k;
    cin >> x >> y >> k;
    int x_steps = x / k + (x % k == 0 ? 0 : 1);
    int y_steps = y / k + (y % k == 0 ? 0 : 1);
    if (x_steps <= y_steps) {
        cout << 2 * 1ll * y_steps << nl;
    } else {
        cout << 2 * 1ll * x_steps - 1 << nl;
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
