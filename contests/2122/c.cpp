/* *** PROBLEM: 2122_c_manhattan_pairs
ON: 2025-07-19
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
    vector<pair<int, int>> vpi(n);
    for (int i = 0; i < n; i++) {
        cin >> vpi[i].first >> vpi[i].second;
    }
    multimap<pair<int, int>, int> mp;
    for (int i = 0; i < n; i++) {
        mp.insert({vpi[i], i + 1});
    }
    sort(vpi.begin(), vpi.end(), [](pair<int, int> &p1, pair<int, int> &p2) {
        return p1.first < p2.first;
    });
    vector<pair<int, int>> left, right;
    for (int i = 0; i < n; i++) {
        if (i < n / 2) {
            left.push_back(vpi[i]);
        } else {
            right.push_back(vpi[i]);
        }
    }
    sort(left.begin(), left.end(), [](pair<int, int> &p1, pair<int, int> &p2) {
        return p1.second < p2.second;
    });
    sort(right.begin(), right.end(),
         [](pair<int, int> &p1, pair<int, int> &p2) {
             return p1.second < p2.second;
         });
    for (int i = 0; i < n / 2; i++) {
        auto it1 = mp.find(left[i]);
        auto [_1, val1] = *it1;
        mp.erase(it1);
        auto it2 = mp.find(right[n / 2 - i - 1]);
        auto [_2, val2] = *it2;
        mp.erase(it2);
        cout << val1 << " " << val2 << nl;
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
