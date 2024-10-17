#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

void solution_fn() {
    string s;
    string t;
    cin >> s >> t;
    int i = 0;
    for (; i < min(sz(s), sz(t)); i++) {
        if (s[i] != t[i])
            break;
    }
    cout << (sz(s) + sz(t) - i + (i == 0 ? 0 : 1)) << nl;
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
