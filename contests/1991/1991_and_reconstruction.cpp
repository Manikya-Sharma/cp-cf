#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())

void solution_fn() {
    int n;
    cin >> n;
    vector<int> b(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    vector<int> a(n);
    a[0] = b[0];
    for (int i = 1; i < n - 1; i++) {
        a[i] = b[i - 1] | b[i];
    }
    a[n - 1] = b[n - 2];
    for (int i = 0; i < n - 1; i++) {
        if ((a[i] & a[i + 1]) != b[i]) {
            cout << -1 << nl;
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
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
