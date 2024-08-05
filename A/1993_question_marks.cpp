#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())

void solution_fn() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> arr(4);
    for (auto ch : s) {
        if (ch != '?') {
            arr[ch - 'A']++;
        }
    }
    int ans = 0;
    for (auto opt : arr) {
        if (opt >= n)
            ans += n;
        else
            ans += opt;
    }
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
