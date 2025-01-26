#include <bits/stdc++.h>
using namespace std;

/* *** TEMPLATE *** */

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

/* *** DEBUG *** */

#ifdef LOCAL
#include "/home/manikya/programming/c/cp/cf/utils/header.h"
#else
#define debug(...) ;
#endif

/* *** SOLUTION *** */

void solution_fn() {
    int l, r;
    cin >> l >> r;
    int a = 0, b = 0, c = 0;
    for (int i = 29; i >= 0; i--) {
        if (((l ^ r) >> i) & 1) {
            // l and r differ at this bit
            a |= (1 << i);
            b |= (1 << i) - 1;
            break;
        } else {
            if (((l >> i) & 1)) {
                a |= (1 << i);
                b |= (1 << i);
            }
        }
    }
    // runs at most 3 times
    for (int i = l; i <= r; i++) {
        if (i != a && i != b) {
            c = i;
            break;
        }
    }
    cout << a << " " << b << " " << c << nl;
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
