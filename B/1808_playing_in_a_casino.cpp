#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())

// ref https://codeforces.com/blog/entry/114523
void solution_fn() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> cards(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cards[i][j];
        }
    }
    unsigned long long int result = 0;
    // for each column
    for (int i = 0; i < m; i++) {
        // sort that column
        sort(cards.begin(), cards.end(),
             [i](vector<int>& r1, vector<int>& r2) { return r1[i] < r2[i]; });
        // compute prefixSum for that column
        vector<unsigned long long int> prefixSum(n + 1);
        prefixSum[0] = 0;
        for (int j = 1; j <= n; j++) {
            prefixSum[j] = prefixSum[j - 1] + cards[j - 1][i];
        }
        // find out sum for this column
        unsigned long long int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += cards[j][i] * 1ll * (j + 1) - prefixSum[j + 1];
        }
        result += sum;
    }
    cout << result << nl;
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
