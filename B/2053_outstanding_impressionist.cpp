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

// TODO: TLE
void solution_fn() {
    int n;
    cin >> n;
    vector<pair<int, int>> vpi(n);
    map<int, set<int>> mp;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        vpi[i] = {x, y};
        if (x == y) {
            mp[x].insert(i);
        }
    }
    string ans(n, '1');
    for (int i = 0; i < n; i++) {
        auto [l, r] = vpi[i];
        bool flag = false;
        for (int j = l; j <= r; j++) {
            if (mp[j].find(i) == mp[j].end()) {
                if (mp[j].empty()) {
                    flag = true;
                    break;
                }
            } else {
                if (mp[j].size() == 1) {
                    flag = true;
                    break;
                }
            }
        }
        if (!flag) {
            ans[i] = '0';
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
