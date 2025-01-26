#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

void solution_fn() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int i = 0, j = n - 1;
    ll sum = accumulate(a.begin(), a.end(), 0);
    while (k != 0) {
        if (k == 1) {
            if (a[i] + a[i + 1] < a[j]) {
                i += 2;
                sum -= (a[i] * 1ll + a[i + 1]);
            }
        } else {
            if (a[i] * 1ll + a[i + 1] < a[j - 1]) {
                i += 2;
                sum -= (a[i] * 1ll + a[i + 1]);
            } else {
                j--;
                sum -= a[j];
            }
        }
        k--;
    }
    cout << sum << nl;
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
