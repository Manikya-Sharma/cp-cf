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
    int n, m, k;
    cin >> n >> m >> k;
    vi a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    set<int> q;
    for (int i = 0; i < k; i++) {
        int elem;
        cin >> elem;
        q.insert(elem);
    }
    if (k == n) {
        string ans(m, '1');
        cout << ans << nl;
        return;
    }
    if (k < n - 1) {
        string ans(m, '0');
        cout << ans << nl;
        return;
    }
    string ans;
    for (auto& elem : a) {
        if (q.find(elem) != q.end()) {
            ans.push_back('0');
        } else {
            ans.push_back('1');
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
