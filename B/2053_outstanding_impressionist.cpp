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
    vector<pair<int, int>> vpi(n);
    vector<int> freq(2 * n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> vpi[i].first;
        cin >> vpi[i].second;
        if (vpi[i].first == vpi[i].second) {
            freq[vpi[i].first]++;
        }
    }
    vector<int> prefix(2 * n + 1);
    prefix[0] = 0;
    prefix[0] = 0;
    for (int i = 1; i < 2 * n + 1; i++) {
        prefix[i] = prefix[i - 1] + (freq[i] > 0);
    }
    for (int i = 0; i < n; i++) {
        auto [l, r] = vpi[i];
        if (l == r) {
            if (freq[l] > 1) {
                cout << 0;
            } else {
                cout << 1;
            }
            continue;
        }
        int size = r - l + 1;
        int ex = prefix[r] - prefix[l - 1];
        if (ex >= size) {
            cout << 0;
        } else {
            cout << 1;
        }
    }
    cout << nl;
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
