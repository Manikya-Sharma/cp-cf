#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

void solution_fn() {
    int x, y, k;
    cin >> x >> y >> k;
    int side = min(x, y);
    cout << 0 << " " << side << " " << side << " " << 0 << nl;
    cout << 0 << " " << 0 << " " << side << " " << side << nl;
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
