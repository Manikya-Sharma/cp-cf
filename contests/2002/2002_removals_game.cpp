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
    vi a(n);
    vi b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int i = 0, j = n - 1;
    bool flag = false;
    while (i < n) {
        if (a[i] != b[j]) {
            flag = true;
            break;
        }
        i++;
        j--;
    }
    if (!flag) {
        cout << "Bob" << nl;
        return;
    }
    i = 0;
    j = 0;
    flag = false;
    while (i < n) {
        if (a[i] != b[j]) {
            flag = true;
            break;
        }
        i++;
        j++;
    }
    if (!flag) {
        cout << "Bob" << nl;
        return;
    }
    cout << "Alice" << nl;
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
