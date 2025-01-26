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
    sort(a.begin(), a.end());
    long long moves = 0;
    int dec = 0;
    for (int i = 0; i < n; i++) {
        a[i] -= dec;
        if (a[i] < 0)
            continue;
        long long out = min(k * 1ll, a[i] * 1ll * (n - i));
        dec += a[i];
        moves += out;
        k -= out;
        if (k != 0)
            moves++;
        else
            break;
    }
    cout << moves << nl;
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
