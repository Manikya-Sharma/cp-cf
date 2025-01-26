#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

// TODO: WA
void solution_fn() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    vector<string> s(m);
    for (int i = 0; i < m; i++) {
        cin >> s[i];
    }
    for (auto str : s) {
        if (sz(str) != n) {
            cout << "NO" << nl;
            continue;
        }
        unordered_map<char, int> mp;
        unordered_map<char, bool> vis;
        unordered_map<int, char> mp_num;
        unordered_map<int, bool> vis_num;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (vis[str[i]] && mp[str[i]] != a[i]) {
                cout << "NO" << nl;
                flag = true;
                break;
            } else if (!vis[str[i]]) {
                vis[str[i]] = 1;
                mp[str[i]] = a[i];
            }
            if (vis_num[a[i]] && mp_num[a[i]] != str[i]) {
                cout << "NO" << nl;
                flag = true;
                break;
            } else if (!vis_num[a[i]]) {
                vis_num[a[i]] = 1;
                mp_num[a[i]] = str[i];
            }
        }
        if (!flag)
            cout << "YES" << nl;
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
