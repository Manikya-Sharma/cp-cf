#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

ll dist(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * 1ll * (x1 - x2) + (y1 - y2) * 1ll * (y1 - y2);
}

void solution_fn() {
    int n;
    cin >> n;
    vector<pair<int, int>> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i].first >> c[i].second;
    }
    int xs, ys;
    cin >> xs >> ys;
    int xt, yt;
    cin >> xt >> yt;

    ll d = dist(xs, ys, xt, yt);
    for (auto [x, y] : c) {
        if (dist(x, y, xt, yt) <= d) {
            cout << "NO" << nl;
            return;
        }
    }
    cout << "YES" << nl;
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
