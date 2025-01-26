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
    int n, x;
    cin >> n >> x;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> mp;
    for (int i=0; i<n; i++) {
        mp[a[i]]++;
    }
    int mex = 0;
    while (true) {
        if (mp[mex] > 0) {
            mex++;
        } else if (mp[mex-x] > 1) {
            mp[mex-x]--;
            mp[mex]++;
            mex++;
        } else {
            break;
        }
    }
    cout << mex << nl;
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
