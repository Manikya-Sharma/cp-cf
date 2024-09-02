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
    vi freq(n + 1, 0);
    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
    }
    int max_freq = 0;
    for (int i = 1; i <= n; i++) {
        max_freq = max(max_freq, freq[i]);
    }
    cout << n - max_freq << nl;
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
