/* *** PROBLEM: 2098_b_sasha_and_the_apartment_purchase
ON: 2025-04-26
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (n % 2 != 0) {
        int range = k / 2 + k % 2;
        int low = n / 2 - range;
        int high = n / 2 + range;
        cout << a[high] - a[low] + 1 << nl;
    } else {
        int range = k / 2;
        int low = n / 2 - 1 - range;
        int high = n / 2 + range;
        cout << a[high] - a[low] + 1 << nl;
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

