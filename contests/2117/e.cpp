/* *** PROBLEM: 2117_e_lost_soul
ON: 2025-06-08
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

// TODO: WA
void solution_fn() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + (a[i - 1] == b[i - 1]);
    }
    vector<int> same1(n, -1), diff1(n, -1);
    vector<int> same2(n, -1), diff2(n, -1);
    map<int, int> mp1, mp2;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (mp1.count(a[i])) {
                same1[i] = mp1[i];
            }
            if (mp2.count(b[i])) {
                same2[i] = mp1[i];
            }
            mp1[a[i]] = i;
            mp2[b[i]] = i;
            if (mp2.count(a[i])) {
                diff1[i] = mp2[a[i]];
            }
            if (mp1.count(b[i])) {
                diff2[i] = mp1[b[i]];
            }
        } else {
            if (mp1.count(b[i])) {
                same1[i] = mp1[i];
            }
            if (mp2.count(a[i])) {
                same2[i] = mp1[i];
            }
            mp1[b[i]] = i;
            mp2[a[i]] = i;
            if (mp2.count(b[i])) {
                diff1[i] = mp2[b[i]];
            }
            if (mp1.count(a[i])) {
                diff2[i] = mp1[a[i]];
            }
        }
    }
    int ans = prefix[n];
    for (int i = n - 1; i >= 0; i--) {
        int res1 = 1 + diff1[i];
        int res2 = same1[i] == -1
                       ? -1
                       : (same1[i] - (prefix[i + 1] - prefix[same1[i]]) != 0);
        int res3 = 1 + diff2[i];
        int res4 = same2[i] == -1
                       ? -1
                       : (same2[i] - (prefix[i + 1] - prefix[same2[i]]) != 0);
        ans = max(ans, max(res1, max(res2, max(res3, res4))));
    }
    cout << ans << nl;
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

