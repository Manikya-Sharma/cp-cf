#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

bool is_valid(vector<ll>& a, ll k) {
    int n = sz(a);
    bool b_color = false;
    int i = 0;
    while (i < n - 1) {
        if (a[i + 1] - a[i] <= k) {
            i += 2;
        } else {
            if (b_color)
                return false;
            b_color = true;
            i++;
        }
    }
    if (i == n-1) {
        return !b_color;
    }
    return true;
}

void solution_fn() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll start = 1;
    ll end = 0;
    for (int i = 0; i < n - 1; i++) {
        end = max(end, a[i + 1] - a[i]);
    }
    while (start <= end) {
        ll mid = start + (end - start) / 2;
        if (is_valid(a, mid)) {
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
