#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

void solution_fn() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int i = 0, j = 0;
    int max_len = 0;
    set<int> st;

    while (j < sz(a)) {
        if (st.find(a[j]) != st.end()) {
            j++;
        } else {
            if (j > 0 && a[j] != a[j - 1] + 1) {
                st.clear();
                i = j;
                st.insert(a[j]);
                j++;
                continue;
            }
            if (sz(st) < k) {
                st.insert(a[j]);
                j++;
            } else {
                int elem = a[i];
                while (a[i] == elem)
                    i++;
                st.erase(elem);
            }
        }
        max_len = max(max_len, j - i);
        if (i > j)
            break;
    }
    cout << max_len << nl;
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
