/* ***  METADATA
PROBLEM: 2064_b_variety_is_discouraged
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
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> freq;
    for (auto& elem : a) {
        freq[elem]++;
    }
    int ans = 0;
    pair<int, int> res;
    int i = 0;
    while (i < n) {
        if (freq[a[i]] == 1) {
            int j = i + 1;
            while (j < n) {
                if (freq[a[j]] != 1) {
                    break;
                }
                j++;
            }
            if (j - i > ans) {
                ans = j - i;
                res = {i + 1, j};
            }
            i = j;
        } else {
            i++;
        }
    }
    if (ans == 0) {
        cout << 0 << nl;
    } else {
        cout << res.first << " " << res.second << nl;
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
