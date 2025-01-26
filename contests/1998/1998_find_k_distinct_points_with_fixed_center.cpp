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
    vector<int> xi(k);
    vector<int> yi(k);
    for (int i = 0; i < k - 1; i++) {
        xi[i] = i - 500;
        yi[i] = i - 500;
    }
    int xn = k * x - ((k - 2) * (k - 1) / 2 - 500 * (k - 1));
    int yn = k * y - ((k - 2) * (k - 1) / 2 - 500 * (k - 1));
    xi[k - 1] = xn;
    yi[k - 1] = yn;
    for (int i = 0; i < k; i++) {
        cout << xi[i] << " " << yi[i] << nl;
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
