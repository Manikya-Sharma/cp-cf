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
    int n, m;
    cin >> n >> m;
    vi pos(n * m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int card;
            cin >> card;
            pos[card] = i;
        }
    }
    for (int i = 0; i + n < n * m; i++) {
        if (pos[i] != pos[i + n]) {
            cout << -1 << nl;
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << pos[i] + 1 << " \n"[i == n - 1];
    }
}

int main() {
    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solution_fn();
    }
    return 0;
}
