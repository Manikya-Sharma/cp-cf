/* *** PROBLEM: 2086_d_even_string
ON: 2025-04-04
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
    int freq[26];
    int n = 0;
    for (int i = 0; i < 26; i++) {
        cin >> freq[i];
        n += freq[i];
    }
    vector<int> prev(n / 2 + 1, 0);
    prev[0] = 1;
    for (int i = 0; i < 26; i++) {
        vector<int> curr(n / 2 + 1);
        for (int j = 0; j <= n / 2; j++) {
            curr[j] = prev[j];
            if (freq[i] == 0)
                continue;
            if (j - freq[i] >= 0) {
                curr[j] += prev[j - freq[i]];
            }
        }
        prev = curr;
    }
    int ways = prev[n / 2];
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

