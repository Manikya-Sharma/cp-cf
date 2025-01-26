#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())

// ref: https://codeforces.com/blog/entry/123530
void solution_fn() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    ll xp = 0;
    ll a_sum = 0;
    ll max_b = 0;
    for (int i = 0; i < min(n, k); i++) {
        a_sum += a[i];
        max_b = max(max_b, b[i] * 1ll);
        xp = max(xp, a_sum + (k - i - 1) * max_b);
    }
    cout << xp << nl;
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
