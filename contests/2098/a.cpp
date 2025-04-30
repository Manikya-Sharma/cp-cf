/* *** PROBLEM: 2098_a_vadims_collection
ON: 2025-04-26
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
    string s;
    cin >> s;
    map<char, int> mp;
    for (int i = 0; i < 10; i++) {
        mp[s[i]]++;
    }
    string ans;
    for (int i = 0; i < 10; i++) {
        bool flag = false;
        for (int j = 10 - i - 1; j <= 9; j++) {
            if (mp[j + '0'] > 0) {
                ans.push_back(j + '0');
                mp[j + '0']--;
                flag = true;
                break;
            }
        }
        if (!flag) {
            ans.push_back(10 - i - 1 + '0');
            mp[10 - i - 1 + '0']--;
        }
    }
    cout << ans << nl;
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

