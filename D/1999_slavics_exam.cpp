#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())

// TODO: MLE
bool solve_mem(string& s, string& t, int i, int j, vector<vector<int>>& dp) {

    if (j == sz(t))
        return true;
    if (i == sz(s))
        return false;
    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == t[j]) {
        dp[i][j] = solve_mem(s, t, i + 1, j + 1, dp);
        return dp[i][j];
    }

    if (s[i] == '?') {
        bool a1 = solve_mem(s, t, i + 1, j, dp);
        bool a2 = solve_mem(s, t, i + 1, j + 1, dp);
        if (a1) {
            s[i] = 'a';
            dp[i][j] = a1;
            return dp[i][j];
        } else if (a2) {
            s[i] = t[j];
            dp[i][j] = a2;
            return dp[i][j];
        }
    }

    dp[i][j] = solve_mem(s, t, i + 1, j, dp);
    return dp[i][j];
}

void solution_fn() {
    string s;
    cin >> s;
    string t;
    cin >> t;

    vector<vector<int>> dp(sz(s), vector<int>(sz(t), -1));

    bool ans = solve_mem(s, t, 0, 0, dp);
    cout << ans << " " << s << nl;
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
