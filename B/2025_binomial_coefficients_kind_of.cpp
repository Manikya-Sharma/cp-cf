#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int exponen(int num) {
#define MOD int(1e9 + 7)
    if (num == 0)
        return 1;
    if (num % 2 == 0) {
        int val = exponen(num / 2);
        return ((val % MOD) * 1ll * (val % MOD)) % MOD;
    } else {
        return (2 * exponen(num - 1) % MOD) % MOD;
    }
#undef MOD
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vi a(n);
    vi b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for (auto& num : b) {
        cout << exponen(num) << nl;
    }

    return 0;
}
