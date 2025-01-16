#include <bits/stdc++.h>
using namespace std;

/* *** TEMPLATE *** */

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;

/* *** DEBUG *** */

#ifdef LOCAL
#include "/home/manikya/programming/c/cp/cf/utils/header.h"
#else
#define debug(...) ;
#endif

/* *** SOLUTION *** */

// TODO: WA
void solution_fn() {
    int n, k;
    cin >> n >> k;
    ll maxx = (1 << (min(63, n - 1)));
    if (k > maxx) {
        cout << -1 << nl;
        return;
    }
    vi ans(n, 0);
    set<int> st;
    int next = 1;
    ll start = 1, end = maxx;
    int i = 0;
    while (next <= n) {
        ll mid = start + (end - start) / 2;
        if (k <= mid) {
            st.insert(next);
            ans[i++] = next++;
            end = mid - 1;
        } else {
            next++;
            start = mid;
        }
    }
    next = n;
    for (int j = 0; j < n; j++) {
        if (ans[j] == 0) {
            while (st.count(next)) {
                next--;
            }
            ans[j] = next--;
        }
    }
    for (int j = 0; j < n; j++) {
        cout << ans[j] << " \n"[j == n - 1];
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
