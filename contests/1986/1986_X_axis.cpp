#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())

void solution_fn() {
    vector<int> inp(3);
    for (int i = 0; i < 3; i++) {
        cin >> inp[i];
    }
    sort(inp.begin(), inp.end());
    int sum = 0;
    sum += inp[1] - inp[0];
    sum += inp[2] - inp[1];
    cout << sum << nl;
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
