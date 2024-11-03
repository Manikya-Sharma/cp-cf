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
    vi a(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
    }
    int count = 0;
    for (auto& elem : a) {
        count += elem;
    }
    int min_val = count % 2;
    int max_val = count > n ? 2 * n - count : count;
    cout << min_val << " " << max_val << nl;
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
