#include <bits/stdc++.h>
using namespace std;

/* *** TEMPLATE *** */

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;

/* *** DEBUG *** */

#ifdef LOCAL
#include "/home/manikya/programming/c/cp/cf/utils/header.h"
#else
#define debug(...) ;
#endif

/* *** SOLUTION *** */

void solution_fn() {
    int n, l, r;
    cin >> n >> l >> r;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int size = r - l + 1;

    // left
    priority_queue<int, vi, greater<int>> pq;
    for (int i = 0; i < l - 1; i++) {
        pq.push(a[i]);
    }
    for (int i = l - 1; i < r; i++) {
        pq.push(a[i]);
    }
    ll left = 0;
    for (int i = 0; i < size; i++) {
        left += pq.top();
        pq.pop();
    }

    while (!pq.empty())
        pq.pop();

    // right
    for (int i = r; i < n; i++) {
        pq.push(a[i]);
    }
    for (int i = l - 1; i < r; i++) {
        pq.push(a[i]);
    }
    ll right = 0;
    for (int i = 0; i < size; i++) {
        right += pq.top();
        pq.pop();
    }
    cout << min(left, right) << nl;
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
