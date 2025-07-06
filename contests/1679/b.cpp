/* *** PROBLEM: 1679_b_stone_age_problem
ON: 2025-05-24
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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll sum = accumulate(a.begin(), a.end(), 0ll);
    int prev = -1;
    set<int> *unset = new set<int>();
    while (q--) {
        int qq;
        cin >> qq;
        if (qq == 1) {
            int i, x;
            cin >> i >> x;
            if (prev == -1 || unset->count(i - 1)) {
                sum -= a[i - 1];
            } else {
                sum -= prev;
                unset->insert(i - 1);
            }
            sum += x;
            a[i - 1] = x;
        } else {
            int x;
            cin >> x;
            prev = x;
            delete unset;
            unset = new set<int>();
            sum = n * 1ll * x;
        }
        cout << sum << nl;
    }
    delete unset;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution_fn();
    return 0;
}

