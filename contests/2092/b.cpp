/* *** PROBLEM: 2092_b_lady_bug
ON: 2025-03-30
BY: Manikya
*** */

#include <bits/stdc++.h>
using namespace std;

/* *** TEMPLATE *** */

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())

/* *** DEBUG *** */

#ifdef LOCAL
#include "/home/manikya/programming/c/cp/cf/utils/header.h"
#else
#define debug(...) ;
#endif

/* *** SOLUTION *** */

inline int ceil_div(int a, int b) {
    return (a + b - 1) / b;
}

void solution_fn() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<int> g1, g2;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            g1.push_back(a[i] - '0');
            g2.push_back(b[i] - '0');
        } else {
            g1.push_back(b[i] - '0');
            g2.push_back(a[i] - '0');
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        count += g1[i] == 0;
    }
    if (count < ceil_div(n, 2)) {
        cout << "NO" << nl;
        return;
    }
    count = 0;
    for (int i = 0; i < n; i++) {
        count += g2[i] == 0;
    }
    if (count >= n / 2) {
        cout << "YES" << nl;
    } else {
        cout << "NO" << nl;
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

