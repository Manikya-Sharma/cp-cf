/* *** PROBLEM: 1741_d_masha_and_a_beautiful_tree
ON: 2025-04-21
BY: Manikya
*** */

#include <bits/stdc++.h>
using namespace std;

/* *** TEMPLATE *** */

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())

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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> mm(a);

    int swaps = 0;
    for (int i = n; i > 0; i /= 2) {
        vector<int> temp(i / 2);
        for (int j = i - 1; j > 0; j -= 2) {
            if (mm[j] < mm[j - 1]) {
                swaps++;
            }
            temp[j / 2] = min(mm[j], mm[j - 1]);
        }
        for (int j = 1; j < i / 2; j++) {
            if (abs(temp[j] - temp[j - 1]) < 2 * n / i) {
                cout << -1 << nl;
                return;
            }
        }
        mm = temp;
    }
    cout << swaps << nl;
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

