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
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int min_cost = 1e9;
    for (int i = 0; i < n; i++) {
        int cost = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[i]) {
                cost++;
            }
        }
        min_cost = min(min_cost, cost);
    }
    cout << min_cost << nl;
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
