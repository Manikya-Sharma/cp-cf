/* *** PROBLEM: 2096_b_wonderful_gloves
ON: 2025-04-19
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

bool is_possible(vector<int>& l, vector<int>& r, ll x, int k) {
    int n = sz(l);
    for (int i = 0; i < n; i++) {
        x -= l[i];
        if (x <= 0)
            return false;
    }
    int count = 0;
    for (int i = n - 1; i >= 0; i--) {
        x -= r[i];
        count++;
        if (x <= 0)
            break;
    }
    return count >= k;
}

void solution_fn() {
    int n, k;
    cin >> n >> k;
    vector<int> l(n);
    ll sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> l[i];
        sum1 += l[i];
    }
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
        sum2 += r[i];
    }

    vector<int> maxes(n), mins(n);
    for (int i = 0; i < n; i++) {
        maxes[i] = max(l[i], r[i]);
        mins[i] = min(l[i], r[i]);
    }

    sort(mins.begin(), mins.end());

    ll start = 0, end = sum1 + sum2;
    while (start <= end) {
        ll mid = start + (end - start) / 2;
        if (is_possible(maxes, mins, mid, k)) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    cout << start << nl;
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

