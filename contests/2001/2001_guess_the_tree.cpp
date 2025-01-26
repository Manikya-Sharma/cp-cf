#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

// ref: https://www.youtube.com/watch?v=aEJg_fFxYmU&t=2147s 
void solution_fn() {
    int n;
    cin >> n;
    // Question: Is root always guaranteed to be 1?

    vector<int> parent(n + 1);

    for (int u = 2; u <= n; u++) {
        int start = 1;
        int mid = -1;
        while (true) {
            cout << "? " << start << " " << u << endl;
            cin >> mid;
            if (mid == start) {
                parent[u] = mid;
                break;
            }
            start = mid;
        }
    }
    cout << "!";
    for (int i = 2; i <= n; i++) {
        cout << " " << i << " " << parent[i];
    }
    cout << endl;
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
