#include <bits/stdc++.h>
using namespace std;

/* *** TEMPLATE *** */

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;

/* *** DEBUG *** */

#ifdef LOCAL
#include "/home/manikya/programming/c/cp/cf/utils/header.h"
#else
#define debug(...) ;
#endif

/* *** SOLUTION *** */

void solution_fn() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int val = a + b;
    int val1 = (a + b == val) + (b + val == c) + (val + c == d);
    val = c - b;
    int val2 = (a + b == val) + (b + val == c) + (val + c == d);
    val = d - c;
    int val3 = (a + b == val) + (b + val == c) + (val + c == d);
    cout << max(val1, max(val2, val3)) << nl;
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
