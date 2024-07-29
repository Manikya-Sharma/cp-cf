#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;

// hint-ref: https://codeforces.com/blog/entry/129620
void solution_fn() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << (a[0] == 0 ? 1 : 0) << nl;
        return;
    }
    int max_idx = 0;
    ll sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > a[max_idx])
            max_idx = i;
        sum += a[i];
        if (sum - a[max_idx] == a[max_idx]) {
            count++;
        }
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
