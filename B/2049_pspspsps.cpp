#include <bits/stdc++.h>
#include <cinttypes>
using namespace std;

/* *** TEMPLATE *** */

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

/* *** DEBUG *** */

#ifdef LOCAL
#include "/home/manikya/programming/c/cp/cf/utils/header.h"
#else
#define debug(...) ;
#endif

/* *** SOLUTION *** */

// TODO: WA
void solution_fn() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<int> st;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'p') {
            if (st.empty()) {
                st.insert(0);
                st.insert(i);
            } else {
                if (st.find(0) == st.end() && st.find(i) == st.end()) {
                    cout << "NO" << nl;
                    return;
                }
                st.insert(0);
                st.insert(i);
            }
        } else if (s[i] == 's') {
            if (st.empty()) {
                st.insert(i);
                st.insert(n - 1);
            } else {
                if (st.find(i) == st.end() && st.find(n - 1) == st.end()) {
                    cout << "NO" << nl;
                    return;
                }
                st.insert(i);
                st.insert(n - 1);
            }
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
