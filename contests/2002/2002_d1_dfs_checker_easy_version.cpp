#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpi;

bool solve(unordered_map<int, int>& parent, vi& p, int start, int end) {
    if (start >= end)
        return true;
    int mid = (end + start + 1) / 2;
    int node1 = start + 1;
    int node2 = mid + 1;
    if (parent[p[node1]] != p[start] || parent[p[node2]] != p[start]) {
        return false;
    }
    return solve(parent, p, start + 1, mid) && solve(parent, p, mid + 1, end);
}

// TODO: NOT DONE
void solution_fn() {
    int n, q;
    cin >> n >> q;
    vvi adj(n + 1);
    unordered_map<int, int> parent;
    for (int i = 2; i <= n; i++) {
        int elem;
        cin >> elem;
        parent[i] = elem;
    }
    vi p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    vpi queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].first >> queries[i].second;
    }

    for (auto [x, y] : queries) {
        swap(p[x - 1], p[y - 1]);
        bool result = solve(parent, p, 0, n - 1);
        if (result) {
            cout << "YES" << nl;
        } else {
            cout << "NO" << nl;
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
