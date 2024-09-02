#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

void solution_fn() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    unordered_map<char, int> mp;
    for (auto& ch : s) {
        mp[ch]++;
    }
    vector<pair<int, char>> v;
    for (auto& [ch, freq] : mp) {
        v.push_back({freq, ch});
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    string output(n, '#');
    int idx = 0;

    for (auto& [freq, ch] : v) {
        while (freq--) {
            output[idx] = ch;
            idx = idx + 2;
            if (idx >= n)
                idx = 1;
        }
    }

    cout << output << nl;
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
