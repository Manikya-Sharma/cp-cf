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
    sort(a.begin(), a.end());
    bool found = false;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] != a[i + 1])
            continue;
        int x = 0, y = 1;
        while (x < n && y < n) {
            while (y == i || y == i + 1)
                y++;
            while (x == i || x == i + 1)
                x++;
            if (y <= x)
                y = x + 1;
            if (y >= n)
                break;
            if (a[y] - a[x] < 2 * a[i]) {
                cout << a[i] << " " << a[i + 1] << " " << a[x] << " " << a[y]
                     << nl;
                found = true;
                break;
            }
            x++;
            y++;
        }
        if (found)
            break;
    }
    if (!found) {
        cout << -1 << nl;
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
