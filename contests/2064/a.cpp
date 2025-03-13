/* ***  METADATA
PROBLEM: 2064_a_brogramming_contest
ON: 2025-02-16
BY: Manikya
*** */

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
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool exp_one = true;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (exp_one && s[i] == '1') {
            count++;
            exp_one = false;
        } else if (!exp_one && s[i] == '0') {
            count++;
            exp_one = true;
        }
    }
    cout << count << nl;
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
