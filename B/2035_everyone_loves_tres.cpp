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
    if (n == 1 || n == 3) {
        cout << -1 << nl;
        return;
    }
    vi a(n);
    int i = 1;
    a[n - i] = 6;
    i++;
    a[n - i] = 6;
    i++;
    if (n % 2 == 1) {
        a[n - i] = 3;
        i++;
        a[n - i] = 6;
        i++;
        a[n - i] = 3;
        i++;
    }
    while (i <= n) {
        a[n - i] = 3;
        i++;
    }
    for (auto& elem : a) {
        cout << elem;
    }
    cout << nl;
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
