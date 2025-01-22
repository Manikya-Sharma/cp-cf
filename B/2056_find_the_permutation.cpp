#include <bits/stdc++.h>
using namespace std;

/* *** TEMPLATE *** */

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;

/* *** DEBUG *** */

#ifdef LOCAL
#include "/home/manikya/programming/c/cp/cf/utils/header.h"
#else
#define debug(...) ;
#endif

/* *** SOLUTION *** */

void dfs(int node, vector<string>& adj, vi& visited, stack<int>& st) {
    visited[node] = 1;
    for (int i = 0; i < sz(adj); i++) {
        if (!visited[i] && adj[node][i] == '1') {
            dfs(i, adj, visited, st);
        }
    }
    st.push(node + 1);
}

void solution_fn() {
    int n;
    cin >> n;
    vector<string> adj(n);
    for (int i = 0; i < n; i++) {
        cin >> adj[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            adj[i][j] = '0';
        }
    }

    vi visited(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }
    vi ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
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
