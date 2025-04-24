/* *** PROBLEM: 1676_g_white_black_balanced_subtrees
ON: 2025-04-13
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

pair<int, int> dfs(vector<vector<int>>& adj, int node, string& color,
                   int& ans) {
    int bcount = 0, wcount = 0;
    if (color[node] == 'W') {
        wcount++;
    } else {
        bcount++;
    }
    for (auto& nbr : adj[node]) {
        auto [b, w] = dfs(adj, nbr, color, ans);
        bcount += b;
        wcount += w;
    }
    if (bcount == wcount) {
        ans++;
    }
    return {bcount, wcount};
}

void solution_fn() {
    int n;
    cin >> n;
    vector<int> p(n - 1);
    for (int i = 0; i < n - 1; i++) {
        int a;
        cin >> a;
        p[i] = a - 1;
    }
    string color;
    cin >> color;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        adj[p[i - 1]].push_back(i);
    }
    int ans = 0;
    dfs(adj, 0, color, ans);
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

