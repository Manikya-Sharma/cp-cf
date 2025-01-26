#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())

void solution_fn() {
    int n, m;
    cin >> n >> m;
    vector<char> existing(n);
    for (int i = 0; i < n; i++) {
        cin >> existing[i];
    }
    unordered_map<char, int> mp;
    for (auto ch : existing) {
        mp[ch]++;
    }
    int count = 0;
    for (int i = 0; i < 7; i++) {
        if (mp[i + 'A'] < m)
            count += m - mp[i + 'A'];
    }
    cout << count << nl;
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
