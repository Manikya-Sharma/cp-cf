/* *** PROBLEM: 1768_c_elemental_decompress
ON: 2025-08-05
BY: Manikya
*** */

#include <bits/stdc++.h>
using namespace std;

/* *** TEMPLATE *** */

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())

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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> freq(n + 1, 0);
    for (auto &elem : a) {
        freq[elem]++;
        if (freq[elem] >= 3) {
            cout << "NO" << nl;
            return;
        }
    }
    set<int> done;
    vector<int> taken(n, -1);
    vector<int> p(n, -1), q(n, -1);
    set<int> st1;
    for (int i = 1; i <= n; i++) {
        st1.insert(i);
    }
    for (int i = 0; i < n; i++) {
        if (freq[a[i]] == 1) {
            p[i] = a[i];
            q[i] = a[i];
        } else {
            if (!done.count(a[i])) {
                p[i] = a[i];
                taken[i] = 0;
                done.insert(a[i]);
            } else {
                q[i] = a[i];
                taken[i] = 1;
            }
        }
        if (st1.count(a[i])) {
            st1.erase(a[i]);
        }
    }
    set<int> st2(st1);
    for (int i = 0; i < n; i++) {
        if (taken[i] != -1) {
            if (taken[i]) {
                auto it = st1.upper_bound(q[i]);
                if (it == st1.begin()) {
                    cout << "NO" << nl;
                    return;
                }
                it = prev(it);
                if (*it > q[i]) {
                    cout << "NO" << nl;
                    return;
                }
                p[i] = *it;
                st1.erase(it);
            } else {
                auto it = st2.upper_bound(p[i]);
                if (it == st2.begin()) {
                    cout << "NO" << nl;
                    return;
                }
                it = prev(it);
                if (*it > p[i]) {
                    cout << "NO" << nl;
                    return;
                }
                q[i] = *it;
                st2.erase(it);
            }
        } else {
            assert(p[i] != -1 && q[i] != -1);
        }
    }
    cout << "YES" << nl;
    for (int i = 0; i < n; i++) {
        cout << p[i] << " \n"[i == n - 1];
    }
    for (int i = 0; i < n; i++) {
        cout << q[i] << " \n"[i == n - 1];
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
