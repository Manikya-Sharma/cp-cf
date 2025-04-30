/* *** PROBLEM: 1905_c_largest_subsequence
ON: 2025-04-27
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
    vector<bool> member(n, false);
    char max_val = 0;
    string lon;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] >= max_val) {
            max_val = s[i];
            member[i] = true;
            lon.push_back(max_val);
        }
    }
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (member[i]) {
            s[i] = lon[j++];
        }
    }
    if (is_sorted(s.begin(), s.end())) {
        int k = 0;
        char prev = lon.back();
        for (int l = sz(lon) - 2; l >= 0; l--) {
            if (lon[l] == prev)
                k++;
            else
                break;
        }
        cout << j - k - 1 << nl;
    } else {
        cout << -1 << nl;
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

