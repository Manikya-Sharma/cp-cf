/* *** PROBLEM: 2090_b_pushing_balls
ON: 2025-03-23
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
    int r, c;
    cin >> r >> c;
    vector<vector<bool>> ball(r, vector<bool>(c, false));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char elem;
            cin >> elem;
            if (elem == '1')
                ball[i][j] = true;
        }
    }
    vector<vector<bool>> down(r, vector<bool>(c, false));
    vector<vector<bool>> right(r, vector<bool>(c, false));

    for (int i = 0; i < r; i++) {
        if (ball[i][0]) {
            for (int j = 1; j < c; j++) {
                if (ball[i][j - 1]) {
                    right[i][j] = true;
                } else {
                    break;
                }
            }
        }
    }

    for (int j = 0; j < c; j++) {
        if (ball[0][j]) {
            for (int i = 1; i < r; i++) {
                if (ball[i - 1][j]) {
                    down[i][j] = true;
                } else {
                    break;
                }
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (i == 0 || j == 0)
                continue;
            if (ball[i][j] && !down[i][j] && !right[i][j]) {
                cout << "NO" << nl;
                return;
            }
        }
    }
    cout << "YES" << nl;
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

