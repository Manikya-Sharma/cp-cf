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

// TODO:: WA
void solution_fn() {
    int n;
    cin >> n;
    string s, r;
    cin >> s >> r;
    int i = 0, j = 0;
    while (i < n - 1 && j < n - 1) {
        debug(s);
        if (s[i] == s[i + 1]) {
            i++;
        } else {
            if (i == 0 || s[i - 1] == '2') {
                s[i] = '2';
                s[i + 1] = r[j];
                i++;
                j++;
            } else {
                s[i] = s[i - 1];
                s[i + 1] = r[j];
                j++;
            }
        }
    }
    if (j == n - 1) {
        cout << "YES" << nl;
    } else {
        cout << "NO" << nl;
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
