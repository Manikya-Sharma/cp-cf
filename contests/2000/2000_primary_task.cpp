#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

void solution_fn() {
    int a;
    cin >> a;
    vector<char> digs;
    while (a) {
        digs.push_back(a % 10);
        a /= 10;
    }
    reverse(digs.begin(), digs.end());
    if (digs.size() <= 2) {
        cout << "NO" << nl;
        return;
    }
    if (digs[0] == 1 && digs[1] == 0) {
        if (digs[2] >= 2) {
            cout << "YES" << nl;
            return;
        } else if (digs[2] == 0) {
            cout << "NO" << nl;
            return;
        } else if (digs.size() >= 4) {
            cout << "YES" << nl;
            return;
        }
    }
    cout << "NO" << nl;
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
