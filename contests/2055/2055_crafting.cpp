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

void solution_fn() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vi b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int x = -1;
    int min_gain = 1e9;
    for (int i = 0; i < n; i++) {
        if (a[i] < b[i]) {
            if (x != -1) {
                cout << "NO" << nl;
                return;
            }
            x = i;
        } else {
            min_gain = min(min_gain, a[i] - b[i]);
        }
    }
    if (x == -1) {
        cout << "YES" << nl;
        return;
    }
    if (min_gain < b[x] - a[x]) {
        cout << "NO" << nl;
        return;
    }
    ll loss = (n - 2) * (b[x] - a[x]);
    ll sum = accumulate(a.begin(), a.end(), 0ll);
    ll desired = accumulate(b.begin(), b.end(), 0ll);
    if (sum - loss >= desired) {
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
