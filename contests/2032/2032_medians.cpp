#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

void solution_fn() {
    int n, k;
    cin >> n >> k;

    if (k == n / 2 + n % 2) {
        cout << 1 << nl;
        cout << 1 << nl;
        return;
    }

    int left = k - 1;

    if (left % 2 == 0) {
        if (k <= 2 || k + 2 > n) {
            cout << -1 << nl;
            return;
        }
        cout << 3 << nl;
        cout << 1 << " " << k - 1 << " " << k + 2 << nl;
    } else {
        if (k <= 1 || k + 1 > n) {
            cout << -1 << nl;
            return;
        }
        cout << 3 << nl;
        cout << 1 << " " << k << " " << k + 1 << nl;
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
