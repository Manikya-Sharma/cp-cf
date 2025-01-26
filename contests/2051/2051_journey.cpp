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
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int d = n / (a + b + c) * 3;
    int mod = n % (a + b + c);
    bool flag = false;
    if (mod >= a) {
        flag = true;
        d++;
        mod -= min(mod, a);
    }
    if (flag && mod >= b) {
        d++;
        mod -= min(mod, b);
    }
    cout << d + (mod > 0) << nl;
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
