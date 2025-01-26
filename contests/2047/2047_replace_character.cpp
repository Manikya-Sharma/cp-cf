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

void solution_fn() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    map<char, pair<int, int>> mp;
    for (int i = 0; i < n; i++) {
        char ch = s[i];
        mp[ch].first++;
        mp[ch].second = i;
    }

    vector<pair<int, int>> v;
    for (auto& [_, y] : mp) {
        v.push_back(y);
    }

    sort(v.begin(), v.end());
    s[v[0].second] = s[v.back().second];

    cout << s << nl;
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
