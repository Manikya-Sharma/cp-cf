#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

void solution_fn() {
    int l, r;
    cin >> l >> r;

    ll det_sq = 8 * 1ll * (r - l);
    if (det_sq == 0) {
        cout << 1 << nl;
        return;
    }
    ll n = (sqrt(det_sq + 1ll) - 1) / 2 + 1 * 1ll;
    cout << n << nl;
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
