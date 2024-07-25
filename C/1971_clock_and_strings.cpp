#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;

void solution_fn() {
    int a, b, c, d;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    int m1 = a > b ? a : b;
    int m2 = a > b ? b : a;

    int s1 = c > m2 && c < m1;
    int s2 = d > m2 && d < m1;
    if ((s1 && s2) || (!s1 && !s2)) {
        cout << "NO" << nl;
    } else {
        cout << "YES" << nl;
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
