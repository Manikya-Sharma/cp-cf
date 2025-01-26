#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;

void solution_fn() {
    int n, m, k;
    cin >> n >> m >> k;
    char a[n + 2];
    a[0] = a[n + 1] = 'L';
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int swims = 0;
    int curr_x = 0;
    while (curr_x <= n) {
        if (a[curr_x] == 'L') {
            // jump farthest possible log otherwise water
            int flag = 0;
            for (int i = min(curr_x + m, n + 1); i > curr_x; i--) {
                if (a[i] == 'L') {
                    curr_x = i;
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                for (int i = curr_x + m; i > curr_x; i--) {
                    if (a[i] == 'W') {
                        curr_x = i;
                        flag = 1;
                        break;
                    }
                }
            }
            if (!flag) {
                cout << "NO" << nl;
                return;
            }
        } else if (a[curr_x] == 'W') {
            swims++;
            if (swims > k) {
                cout << "NO" << nl;
                return;
            }
            curr_x++;
            if (a[curr_x] == 'C') {
                cout << "NO" << nl;
                return;
            }
        } else {
            cout << "NO" << nl;
            return;
        }
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
