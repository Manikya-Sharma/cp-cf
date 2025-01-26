#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int idx(int i, int j, int c) {
    return c * i + j;
}

void solution_fn() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int c = 0;
    for (auto ch : s) {
        if (ch == '0')
            break;
        c++;
    }
    if (c == n) {
        if (n == 4) {
            cout << "YES" << nl;
        } else {
            cout << "NO" << nl;
        }
        return;
    }
    c--;
    int r = n / c;
    if (r != c) {
        cout << "NO" << nl;
        return;
    }
    for (int i = 0; i < c; i++) {
        if (s[idx(0, i, c)] != '1' || s[idx(c - 1, i, c)] != '1') {
            cout << "NO" << nl;
            return;
        }
    }
    for (int i = 0; i < c; i++) {
        if (s[idx(i, 0, c)] != '1' || s[idx(i, c - 1, c)] != '1') {
            cout << "NO" << nl;
            return;
        }
    }
    for (int i = 1; i < c - 1; i++) {
        for (int j = 1; j < c - 1; j++) {
            if (s[idx(i, j, c)] != '0') {
                cout << "NO" << nl;
                return;
            }
        }
    }
    cout << "YES" << nl;
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
