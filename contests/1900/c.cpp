/* *** PROBLEM: 1900_c_anjis_binary_tree
ON: 2025-04-23
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

void solution_fn() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        if (l != 0)
            adj[i].push_back({l - 1, s[i] != 'L'});
        if (r != 0)
            adj[i].push_back({r - 1, s[i] != 'R'});
        if (l == 0 && r == 0) {
            adj[i].push_back({n, 0});
        }
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.push({0, 0});
    vector<int> d(n + 1, 1e9);
    d[0] = 0;
    while (!pq.empty()) {
        auto [curr_d, node] = pq.top();
        pq.pop();
        if (node == n)
            continue;
        for (auto& [nbr, nbr_d] : adj[node]) {
            int new_d = curr_d + nbr_d;
            if (new_d < d[nbr]) {
                d[nbr] = new_d;
                pq.push({new_d, nbr});
            }
        }
    }
    cout << d[n] << nl;
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

