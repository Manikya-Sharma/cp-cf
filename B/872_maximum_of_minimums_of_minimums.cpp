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
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (k == 1) {
        cout << *min_element(a.begin(), a.end()) << nl;
        return;
    } else if (k >= 3) {
        cout << *max_element(a.begin(), a.end()) << nl;
        return;
    }
    vi prefix(n + 1, 1e9 + 5);
    for (int i = 1; i <= n; i++) {
        prefix[i] = min(prefix[i - 1], a[i - 1]);
    }
    int right = 1e9 + 5;
    int ans = -1e9 - 5;
    for (int i = n - 1; i >= 0; i--) {
        right = min(right, a[i]);
        int left = prefix[i + 1];
        ans = max(ans, max(right, left));
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}
