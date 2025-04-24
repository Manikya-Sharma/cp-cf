/* *** PROBLEM: 1657_d_vertical_paths
ON: 2025-04-12
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

class DSU {
    vector<int> parent;
    vector<int> size;

   public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b)
            return;
        if (size[a] < size[b]) {
            parent[a] = b;
            size[b] += size[a];
        } else {
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

void dfs(vector<vector<int>>& adj, int root, DSU& dsu, vector<int>& rank) {
    bool merged = false;
    for (auto& nbr : adj[root]) {
        if (!merged) {
            dsu.merge(root, nbr);
            merged = true;
        }
        rank[nbr] = 1 + rank[root];
        dfs(adj, nbr, dsu, rank);
    }
}

void solution_fn() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    vector<vector<int>> adj(n);
    int root = -1;
    for (int i = 0; i < n; i++) {
        int parent = p[i] - 1;
        if (parent == i) {
            root = i;
            continue;
        }
        adj[parent].push_back(i);
    }
    vector<int> rank(n);
    rank[root] = 0;
    DSU dsu(n);
    dfs(adj, root, dsu, rank);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[dsu.find(i)].push_back(i);
    }
    cout << sz(mp) << nl;
    for (auto& [_, path] : mp) {
        cout << sz(path) << nl;
        sort(path.begin(), path.end(),
             [&rank](int a, int b) { return rank[a] < rank[b]; });
        for (int i = 0; i < sz(path); i++) {
            cout << path[i] + 1 << " \n"[i == sz(path) - 1];
        }
    }
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

