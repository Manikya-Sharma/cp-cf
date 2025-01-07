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
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll odd_sum = 0, even_sum = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            odd_sum += a[i];
        } else {
            even_sum += a[i];
        }
    }
    if (even_sum % (n / 2) == 0 && odd_sum % (n / 2 + n % 2) == 0 &&
        even_sum / (n / 2) == odd_sum / (n / 2 + n % 2)) {
        cout << "Yes" << nl;
    } else {
        cout << "No" << nl;
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
