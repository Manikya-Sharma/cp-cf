/* *** PROBLEM: 1692_f_3sum
ON: 2025-04-13
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        a[i] = elem % 10;
    }
    map<int, int> mp;
    for (auto& elem : a) {
        mp[elem]++;
    }
    bool is_possible = false;
    for (int i = 0; i < 23; i++) {
        for (int j = 0; j < 23; j++) {
            for (int k = 0; k < 23; k++) {
                if (i + j + k == 3 || i + j + k == 13 || i + j + k == 23) {
                    mp[i]--;
                    mp[j]--;
                    mp[k]--;
                    if (mp[i] >= 0 && mp[j] >= 0 && mp[k] >= 0) {
                        is_possible = true;
                        break;
                    }
                    mp[i]++;
                    mp[j]++;
                    mp[k]++;
                }
            }
            if (is_possible)
                break;
        }
        if (is_possible)
            break;
    }
    if (is_possible) {
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

