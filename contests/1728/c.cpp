/* *** PROBLEM: 1728_c_digital_logarithm
ON: 2025-06-08
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

int root(int x) {
    int op = 0;
    while (x) {
        x /= 10;
        op++;
    }
    return op;
}

void solution_fn() {
    int n;
    cin >> n;
    priority_queue<int> a, b;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push(x);
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b.push(x);
    }
    int op = 0;
    while (!a.empty()) {
        if (a.top() > b.top()) {
            op++;
            int elem = a.top();
            a.pop();
            elem = root(elem);
            a.push(elem);
        } else if (a.top() < b.top()) {
            op++;
            int elem = b.top();
            b.pop();
            elem = root(elem);
            b.push(elem);
        } else {
            a.pop();
            b.pop();
        }
    }
    cout << op << nl;
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

