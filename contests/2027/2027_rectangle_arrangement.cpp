#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;
typedef vector<vector<int>> vvi;

void solution_fn() {
    int n;
    cin >> n;
    vpi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        cin >> a[i].second;
    }
    int max_w = 0, max_h = 0;
    for (int i = 0; i < n; i++) {
        max_w = max(max_w, a[i].first);
        max_h = max(max_h, a[i].second);
    }
    cout << 2 * (max_w + max_h) << nl;
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
