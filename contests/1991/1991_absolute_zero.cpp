#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())

// TODO: Do it again -> solved from tutorial
void solution_fn() {
    int n;
    cin >> n;
    vector<int> a(n);
    int min_elem = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        min_elem = min(min_elem, a[i]);
    }

    for (int i=0; i<n; i++) {
        if (a[i]%2 != a[0]%2) {
            cout << -1 << nl;
            return;
        }
    }

    cout << 32 << '\n';
    cout << min_elem;
    for (int i = 29; i >= 0; i--) {
      cout << " " << (1 << i);
    }
    cout << " " << 1 << '\n';

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
