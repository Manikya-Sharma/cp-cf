#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

void solution_fn() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> freq(26);
    for (auto ch : s) {
        freq[ch - 'a']++;
    }
    int odd_vals = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 != 0)
            odd_vals++;
    }
    if (k == odd_vals - 1 || k == odd_vals) {
        cout << "YES" << nl;
        return;
    }
    if (k < odd_vals - 1) {
        cout << "NO" << nl;
        return;
    }
    cout << "YES" << nl;
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
