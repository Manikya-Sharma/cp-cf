#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

// TODO: Incomplete
void solution_fn() {
    int n;
    cin >> n;
    vi p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    string s(n, '#');
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vi dp(n, 0);
    for (int i = 0; i < n; i++) {
        dp[i] = solve(p, s, i, p[i], dp);
    }
    for (int i = 0; i < n; i++) {
        cout << dp[i] << " \n"[i == n - 1];
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
