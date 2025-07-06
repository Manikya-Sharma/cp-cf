/* *** PROBLEM: 2117_c_cool_partition
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

bool is_possible(vector<int> &a, int mid, vector<int> &next) {
    int n = sz(a);
    int nxt = 0;
    int temp = nxt;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (i == temp) {
            nxt = max(nxt, next[i]);
            temp = nxt;
            count++;
        }
        nxt = max(nxt, next[i]);
    }
    return count >= mid;
}

void solution_fn() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> mp;
    vector<int> next(n, n);
    for (int i = n - 1; i >= 0; i--) {
        if (mp.count(a[i])) {
            next[i] = mp[a[i]];
        }
        mp[a[i]] = i;
    }
    int start = 1, end = n;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (is_possible(a, mid, next)) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    cout << end << nl;
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

