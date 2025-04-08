/* *** PROBLEM: 1657_c_bracket_sequence_deletion
ON: 2025-04-06
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count = 0;
    int prev_cl = -1;
    int rem = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == ')') {
            if (prev_cl == -1) {
                prev_cl = i;
            } else {
                prev_cl = -1;
                count++;
            }
        } else if (prev_cl == -1) {
            if (i == n - 1) {
                rem = 1;
            } else {
                count++;
                i++;
            }
        }
    }
    if (prev_cl != -1) {
        rem += n - prev_cl;
    }
    cout << count << " " << rem << nl;
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
