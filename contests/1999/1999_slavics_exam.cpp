#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

// ref: https://codeforces.com/blog/entry/132383 
void solution_fn() {
    string s, t;
    cin >> s;
    cin >> t;
    int j = 0;
    for (int i = 0; i < sz(s); i++) {
        if (s[i] == '?') {
            if (j < sz(t))
                s[i] = t[j];
            else
                s[i] = 'j';
        }
        if (j < sz(t) && s[i] == t[j])
            j++;
    }
    if (j < sz(t))
        cout << "NO" << nl;
    else {
        cout << "YES" << nl;
        cout << s << nl;
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
