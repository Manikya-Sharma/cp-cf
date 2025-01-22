#include <bits/stdc++.h>
using namespace std;

/* *** TEMPLATE *** */

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;
typedef pair<int, int> pii;

/* *** DEBUG *** */

#ifdef LOCAL
#include "/home/manikya/programming/c/cp/cf/utils/header.h"
#else
#define debug(...) ;
#endif

/* *** SOLUTION *** */

void solution_fn() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<pii> f_edges(m1);
    for (int i = 0; i < m1; i++) {
        cin >> f_edges[i].first;
        cin >> f_edges[i].second;
    }
    vector<pii> g_edges(m2);
    for (int i = 0; i < m2; i++) {
        cin >> g_edges[i].first;
        cin >> g_edges[i].second;
    }
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
    for (auto& [x, y] : g_edges) {
        adj[x][y] = 1;
        adj[y][x] = 1;
    }
    int ans = 0;
    for (auto& [x, y] : f_edges) {
        if (!adj[x][y]) {
            ans++;
        }
        adj[x][y] = 0;
        adj[y][x] = 0;
    }
    int s2 = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (adj[i][j]) {
                s2++;
            }
        }
    }
    assert(s2 % 2 == 0);
    ans += s2 / 2;
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
