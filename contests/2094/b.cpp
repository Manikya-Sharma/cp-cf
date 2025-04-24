/* *** PROBLEM: 2094_b_bobrito_bandito
ON: 2025-04-15
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

void solution_fn() {
    int n, m, l, r;
    cin >> n >> m >> l >> r;
    int start = 0, end = 0;
    int back = min(m, -l);
    start = -back;
    m -= back;
    int front = min(m, r);
    end += front;
    cout << start << " " << end << nl;
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

