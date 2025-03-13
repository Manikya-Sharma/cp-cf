/* ***  METADATA
PROBLEM: 2067_d_object_identification
ON: 2025-02-12
BY: Manikya
*** */

#include <bits/stdc++.h>
using namespace std;

/* *** TEMPLATE *** */

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
    set<int> st;
    for (int i = 0; i < n; i++) {
        int elem = a[i];
        st.insert(elem);
    }
    for (int i = 1; i <= n; i++) {
        if (!st.count(i)) {
            cout << "? " << i << " " << (i % n) + 1 << endl;
            int d;
            cin >> d;
            if (d == 0) {
                cout << "! A" << endl;
            } else {
                cout << "! B" << endl;
            }
            return;
        }
    }
    int pos1 = -1, posn = -1;
    for (int i = 0; i < n; i++) {
        int elem = a[i];
        if (elem == 1)
            pos1 = i + 1;
        if (elem == n)
            posn = i + 1;
    }
    int d1, d2;
    cout << "? " << pos1 << " " << posn << endl;
    cin >> d1;
    cout << "? " << posn << " " << pos1 << endl;
    cin >> d2;
    if (d1 < n - 1 || d2 < n - 1) {
        cout << "! A" << endl;
        return;
    }
    if (d1 >= n || d2 >= n) {
        cout << "! B" << endl;
        return;
    }
    if (d1 == d2) {
        cout << "! B" << endl;
    } else {
        cout << "! A" << endl;
    }
}

int main() {
    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solution_fn();
    }
    return 0;
}
