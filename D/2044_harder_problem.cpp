#include <bits/stdc++.h>
using namespace std;

/* *** TEMPLATE *** */

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;

/* *** DEBUG *** */

#ifdef LOCAL
#include "/home/manikya/programming/c/cp/cf/utils/header.h"
#else
#define debug(...) ;
#endif

/* *** SOLUTION *** */

void solution_fn() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vi b(n, -1);
    set<int> vis;
    for (int i = 0; i < n; i++) {
        if (!vis.count(a[i]))
            b[i] = a[i];
        vis.insert(a[i]);
    }
    set<int> st;
    for (int i = 1; i <= n; i++) {
        st.insert(i);
    }
    for (int i = 0; i < n; i++) {
        if (b[i] != -1)
            st.erase(b[i]);
    }
    for (int i = 0; i < n; i++) {
        if (b[i] == -1) {
            b[i] = *st.begin();
            st.erase(st.begin());
        }
    }
    for (int i = 0; i < n; i++) {
        cout << b[i] << " \n"[i == n - 1];
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
