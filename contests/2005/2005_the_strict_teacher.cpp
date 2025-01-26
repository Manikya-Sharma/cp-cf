#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

void solve(int a1, int b, int a2, int d) {
    if (b - a1 <= 2 && a2 - b <= 2) {
        cout << d << nl;
        return;
    }
    if (b - a1 == a2 - b) {
        solve(a1 + 1, b, a2 - 1, d + 1);
    } else {
        solve(a1 + 1, b - a1 < a2 - b ? b + 1 : b - 1, a2 - 1, d + 1);
    }
}

void solution_fn() {
    int n, m, q;
    cin >> n >> m >> q;
    vi b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    int d;
    cin >> d;

    int left_teacher = -1, right_teacher = -1;
    for (int i = 0; i < m; i++) {
        if (b[i] < d)
            left_teacher = b[i];
        else if (right_teacher == -1)
            right_teacher = b[i];
    }

    if (left_teacher == -1) {
        cout << (d - 1 + right_teacher - d) << nl;
    } else if (right_teacher == -1) {
        cout << (n - d + n - left_teacher) << nl;
    } else {
        if (d - left_teacher <= 2 && right_teacher - d <= 2) {
            cout << 1 << nl;
            return;
        }
        solve(left_teacher, d, right_teacher, 0);
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
