#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())

// ref: https://codeforces.com/blog/entry/130213
void solution_fn() {
    int x, y;
    cin >> x >> y;
    // find longest common suffix
    int i = 0;
    while ((x & (1 << i)) == (y & (1 << i))) {
        i++;
    }
    cout << (1 << i) << nl;
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
