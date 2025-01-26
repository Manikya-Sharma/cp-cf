#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

void solution_fn() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int i = n - 1;
    while (i > 0) {
        if (a[i] - a[i - 1] < k) {
            k = k - (a[i] - a[i - 1]);
            a[i - 1] = a[i];
        } else {
            a[i - 1] += k;
            k = 0;
        }
        i -= 2;
    }
    i = n - 1;
    ll a_score = 0;
    ll b_score = 0;
    bool flag = true;
    while (i >= 0) {
        if (flag) {
            a_score += a[i];
        } else {
            b_score += a[i];
        }
        flag = !flag;
        i--;
    }
    cout << a_score - b_score << nl;
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
