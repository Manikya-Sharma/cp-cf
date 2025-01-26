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
    unordered_map<int, int> points;
    ll count = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (points[x] != 0) {
            count += n - 2;
            points[x] = 3;
            continue;
        }
        if (y == 0) {
            points[x] = 1;
        } else {
            points[x] = 2;
        }
    }
    for (int x = 1; x < n; x++) {
        if (points[x] != 0 && points[x - 1] != 0 && points[x + 1] != 0) {
            if (points[x] != 3) {
                if (points[x - 1] != points[x] && points[x + 1] != points[x]) {
                    count++;
                }
            } else {
                if (points[x - 1] == 3 && points[x + 1] == 3) {
                    count += 2;
                } else if (points[x - 1] == 3 || points[x + 1] == 3) {
                    count++;
                } else if (points[x + 1] == points[x - 1]) {
                    count++;
                }
            }
        }
    }
    cout << count << nl;
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
