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
    if (k == 4) {
        int even_count = 0;
        int mod = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] % 4 == 0) {
                cout << 0 << nl;
                return;
            }
            if (a[i] % 2 == 0) {
                even_count++;
            }
            mod = max(mod, a[i] % 4);
        }
        mod = 4 - mod;
        if (even_count >= 2) {
            cout << 0 << nl;
            return;
        }
        if (even_count == 1 && even_count < n) {
            cout << min(mod, 1) << nl;
            return;
        }
        if (even_count == 1) {
            cout << min(mod, 2) << nl;
            return;
        }
        if (n - even_count >= 2) {
            cout << min(mod, 2) << nl;
            return;
        }
        cout << min(mod, (4 - a[0] % 4)) << nl;
    }
    int mod = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % k == 0) {
            cout << 0 << nl;
            return;
        }
        mod = max(mod, a[i] % k);
    }
    if (mod == 0) {
        cout << 0 << nl;
    } else {
        cout << (k - mod) << nl;
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
