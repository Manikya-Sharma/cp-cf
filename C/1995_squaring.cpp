#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;

// TODO: TLE

// ref: https://codeforces.com/blog/entry/131847
void solution_fn() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int x = 0;
    int score = 0;
    for (int i = 1; i < n; i++) {
        int temp = a[i];
        while (temp < a[i - 1]) {
            if (temp == 1) {
                cout << -1 << nl;
                return;
            }
            temp *= temp;
            x++;
        }
        int y = 0;
        while (a[i] >= a[i - 1] * a[i - 1]) {
            if (a[i - 1] == 1) {
                y = x;
                break;
            }
            a[i - 1] *= a[i - 1];
            y++;
        }
        x = max(0, x - y);
        score += x;
    }
    cout << score << nl;
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
