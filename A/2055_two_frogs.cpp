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
    int n, a, b;
    cin >> n >> a >> b;

    bool alice = true;
    while (!((a == 1 && b == 2) || (a == 2 && b == 1) ||
             (a == n && b == n - 1) || (a == n - 1 && b == n))) {
        if (alice) {
            if (a < b) {
                a++;
            } else {
                a--;
            }
        } else {
            if (b < a) {
                b++;
            } else {
                b--;
            }
        }
        alice = !alice;
    }
    if (alice) {
        cout << "No" << nl;
    } else {
        cout << "Yes" << nl;
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
