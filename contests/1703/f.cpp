/* *** PROBLEM: 1703_f_yet_another_problem_about_pairs_satisfying_an_inequality
ON: 2025-04-14
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

ll merge_sort(vector<int>& a, vector<int>& b, int start, int end) {
    if (start >= end)
        return 0;
    int mid = start + (end - start) / 2;
    ll left = merge_sort(a, b, start, mid);
    ll right = merge_sort(a, b, mid + 1, end);

    ll count = 0;
    int i = start, j = mid + 1;
    while (i <= mid && j <= end) {
        if (b[i] < a[j]) {
            count += end - j + 1;
            i++;
        } else {
            j++;
        }
    }

    vector<int> ta, tb;
    i = start, j = mid + 1;
    while (i <= mid && j <= end) {
        if (a[i] < a[j]) {
            ta.push_back(a[i]);
            i++;
        } else {
            ta.push_back(a[j]);
            j++;
        }
    }
    while (i <= mid) {
        ta.push_back(a[i]);
        i++;
    }
    while (j <= end) {
        ta.push_back(a[j]);
        j++;
    }
    for (int k = start; k <= end; k++) {
        a[k] = ta[k - start];
    }

    i = start, j = mid + 1;
    while (i <= mid && j <= end) {
        if (b[i] < b[j]) {
            tb.push_back(b[i]);
            i++;
        } else {
            tb.push_back(b[j]);
            j++;
        }
    }
    while (i <= mid) {
        tb.push_back(b[i]);
        i++;
    }
    while (j <= end) {
        tb.push_back(b[j]);
        j++;
    }
    for (int k = start; k <= end; k++) {
        b[k] = tb[k - start];
    }

    return count + left + right;
}

void solution_fn() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> x, y;
    for (int i = 0; i < n; i++) {
        if (a[i] < i + 1) {
            x.push_back(a[i]);
            y.push_back(i + 1);
        }
    }
    ll ans = merge_sort(x, y, 0, sz(x) - 1);
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

