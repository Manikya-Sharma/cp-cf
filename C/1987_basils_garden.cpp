#include <bits/stdc++.h>
using namespace std;

void solution_fn() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    // by looking at tutorial
    int ans = h[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        ans = max(ans + 1, h[i]);
    }
    cout << ans << endl;
}

int main() {
    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solution_fn();
    }
    return 0;
}
