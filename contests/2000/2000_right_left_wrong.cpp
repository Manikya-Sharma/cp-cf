#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

ll solve(string& s, vi& a, int start, int end, vector<ll>& prefix_sum) {
    int fl = -1, lr = -1;
    for (int i = start; i <= end; i++) {
        if (s[i] == 'L') {
            fl = i;
            break;
        }
    }
    for (int i = end; i >= start; i--) {
        if (s[i] == 'R') {
            lr = i;
            break;
        }
    }
    if (fl == -1 || lr < fl)
        return 0;
    return prefix_sum[lr + 1] - prefix_sum[fl] +
           solve(s, a, fl + 1, lr - 1, prefix_sum);
}

void solution_fn() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string s;
    cin >> s;
    vector<ll> prefix_sum(n + 1);
    prefix_sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + a[i - 1];
    }
    long long ans = solve(s, a, 0, n - 1, prefix_sum);
    cout << ans << nl;
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
