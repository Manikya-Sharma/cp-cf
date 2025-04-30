/* *** PROBLEM: 2104_c_card_game
ON: 2025-04-28
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

bool beats(int i, int j, int n) {
    if (i == 0 && j == n - 1) {
        return true;
    }
    if (j == 0 && i == n - 1) {
        return false;
    }
    return i > j;
}

void solution_fn() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            bool flag = false;
            for (int j = 0; j < n; j++) {
                if (s[j] == 'B' && !beats(i, j, n)) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                cout << "Alice" << nl;
                return;
            }
        }
    }
    cout << "Bob" << nl;
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

