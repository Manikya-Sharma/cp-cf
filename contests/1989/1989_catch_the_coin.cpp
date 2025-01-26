#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;

void solution_fn() {
    int x, y;
    cin >> x >> y;
    if (y >= -1)
        cout << "YES" << nl;
    else
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
