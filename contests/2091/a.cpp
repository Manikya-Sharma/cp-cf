/* *** PROBLEM: 2091_a_olympiad_date
ON: 2025-03-25
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
    map<int, int> mp;
    mp[0] = 3;
    mp[1] = 1;
    mp[3] = 1;
    mp[2] = 2;
    mp[5] = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        mp[a[i]]--;
        bool valid = true;
        for (auto& [x, f] : mp) {
            if (f > 0) {
                valid = false;
                break;
            }
        }
        if (valid) {
            cout << i + 1 << nl;
            return;
        }
    }
    cout << 0 << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solution_fn();
    }
    return 0;
}

