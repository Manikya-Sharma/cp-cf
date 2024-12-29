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
    int n;
    ll x, y;
    cin >> n >> x >> y;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    ll sum = 0;
    for (auto& elem : a) {
        sum += elem;
    }

    ll count = 0;

    for (int i = 0; i < n; i++) {
        int start = i + 1;
        int end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            ll new_sum = sum - a[i] - a[mid];
            if (new_sum < x) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        int low = end;

        start = i + 1;
        end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (a[mid] <= a[low]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        low = end;
        if (low == i || sum - a[i] - a[low] < x)
            continue;

        start = i + 1;
        end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            ll new_sum = sum - a[i] - a[mid];
            if (new_sum > y) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        int high = start;
        if (high == n)
            continue;

        start = i + 1;
        end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (a[mid] >= a[high]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        high = start;
        if (sum - a[i] - a[high] > y)
            continue;
        count += max(low - high + 1, 0);
    }
    cout << count << nl;
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
