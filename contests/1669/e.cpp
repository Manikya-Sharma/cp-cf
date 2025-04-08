/* *** PROBLEM: 1669_e_2_letter_strings
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
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    map<string, int> mp;
    for (auto& elem : s) {
        mp[elem]++;
    }
    vector<int> first(12);
    vector<int> second(12);
    for (auto& [str, count] : mp) {
        first[str[0] - 'a'] += count;
        second[str[1] - 'a'] += count;
    }
    ll ans = 0;
    for (int i = 0; i < 12; i++) {
        ll n1 = first[i];
        ans += n1 * (n1 - 1) / 2;
        ll n2 = second[i];
        ans += n2 * (n2 - 1) / 2;
    }
    for (auto& [_, count] : mp) {
        ans -= count * 1ll * (count - 1);
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

