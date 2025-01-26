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
    string n;
    cin >> n;

    ll three_count = 0, two_count = 0, sum = 0;
    for (auto elem : n) {
        elem = elem - '0';
        sum += elem;
        three_count += (elem == 3);
        two_count += (elem == 2);
    }

    two_count = min(two_count, 10ll);
    three_count = min(three_count, 10ll);

    for (int i = 0; i <= two_count; i++) {
        for (int j = 0; j <= three_count; j++) {
            if ((sum + i * 2 + j * 6) % 9 == 0) {
                cout << "Yes" << nl;
                return;
            }
        }
    }
    cout << "No" << nl;
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
