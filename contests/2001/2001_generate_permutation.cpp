#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

void solution_fn() {
    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << -1 << nl;
        return;
    }

    vi ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = i + 1;
    }
    for (int i = 0; i < n - 2; i += 2) {
        swap(ans[i], ans[i + 1]);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
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
