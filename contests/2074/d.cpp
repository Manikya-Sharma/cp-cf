/* *** PROBLEM: 2074_d_counting_points
ON: 2025-03-11
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

inline bool is_possible(int i, int j, int x, int r) {
    return (i - x) * 1ll * (i - x) + j * 1ll * j <= r * 1ll * r;
}

int f(int i, int x, int r) {
    int start = 0, end = r;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (is_possible(i, mid, x, r)) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return end;
}

void solution_fn() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> circles(n);
    for (int i = 0; i < n; i++) {
        cin >> circles[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> circles[i].second;
    }
    sort(circles.begin(), circles.end());
    map<int, int> mp;

    for (auto& [x, r] : circles) {
        for (int i = x - r; i <= x + r; i++) {
            mp[i] = max(mp[i], 2 * f(i, x, r) + 1);
        }
    }

    ll points = 0;
    for (auto& [_, elem] : mp) {
        points += elem;
    }
    cout << points << nl;
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
