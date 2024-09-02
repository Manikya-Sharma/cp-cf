#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

void solution_fn() {
    int l1, r1;
    cin >> l1 >> r1;
    int l2, r2;
    cin >> l2 >> r2;
    int intersection = min(r1, r2) - max(l1, l2);
    if (intersection < 0) {
        cout << 1 << nl;
    } else {
        int gap = intersection + 2;
        if (l1 == l2) {
            gap--;
        }
        if (r1 == r2) {
            gap--;
        }
        cout << gap << nl;
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
