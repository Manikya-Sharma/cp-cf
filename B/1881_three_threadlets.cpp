#include <bits/stdc++.h>
#include <cmath>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

void solution_fn() {
    vector<int> inp(3);
    for (int i = 0; i < 3; i++) {
        cin >> inp[i];
    }
    int min_elem = 1e9;
    for (auto elem : inp)
        min_elem = min(min_elem, elem);
    ll moves = 3;
    for (int i = 0; i < 3; i++) {
        if (moves < 0) {
            cout << "NO" << nl;
            return;
        }
        if (inp[i] == min_elem)
            continue;
        if (inp[i] % min_elem != 0) {
            cout << "NO" << nl;
            return;
        }
        if (moves < inp[i] / min_elem - 1) {
            cout << "NO" << nl;
            return;
        }
        moves = moves - (inp[i] / min_elem - 1);
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
