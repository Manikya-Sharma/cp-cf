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
    int n, d;
    cin >> n >> d;
    vi ans;
    ans.push_back(1);
    if (d % 3 == 0 || n >= 3)
        ans.push_back(3);
    if (d == 5) {
        ans.push_back(5);
    }
    if (d == 7 || (n >= 3)) {
        ans.push_back(7);
    }
    if (d == 9 || (d % 3 == 0 && n >= 3) || n >= 6)
        ans.push_back(9);

    for (int i = 0; i < sz(ans); i++) {
        cout << ans[i] << " \n"[i == sz(ans) - 1];
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
