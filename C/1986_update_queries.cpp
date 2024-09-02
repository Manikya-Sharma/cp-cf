#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

void solution_fn() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vi idx(m);
    for (int i = 0; i < m; i++) {
        cin >> idx[i];
    }
    string c;
    cin >> c;

    sort(idx.begin(), idx.end());
    sort(c.begin(), c.end());

    int i = 0, j = m - 1;
    string desired_c(m, 'a');

    for (int x = 0; x < m - 1; x++) {
        if (idx[x] == idx[x + 1]) {
            desired_c[x] = c[j--];
        } else {
            desired_c[x] = c[i++];
        }
    }
    desired_c[m - 1] = c[j];
    // change s acc. to c
    for (int x = 0; x < m; x++) {
        s[idx[x] - 1] = desired_c[x];
    }
    cout << s << nl;
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
