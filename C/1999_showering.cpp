#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())

void solution_fn() {
    int n, s, m;
    cin >> n >> s >> m;
    vector<pair<int, int>> nums(n);
    for (int i = 0; i < n; i++) {
        pair<int, int> p;
        cin >> p.first;
        cin >> p.second;
        nums[i] = p;
    }
    if (nums[0].first >= s) {
        cout << "YES" << nl;
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        if (nums[i + 1].first - nums[i].second >= s) {
            cout << "YES" << nl;
            return;
        }
    }
    if (m - nums[sz(nums) - 1].second >= s) {
        cout << "YES" << nl;
        return;
    }
    cout << "NO" << nl;
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
