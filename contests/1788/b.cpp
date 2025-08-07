/* *** PROBLEM: 1788_b_sum_of_two_numbers
ON: 2025-08-01
BY: Manikya
*** */

#include <bits/stdc++.h>
#include <iostream>
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
    int a = 0, b = 0;
    bool flag = false;
    int x = 1;
    while (n) {
        int dig = n % 10;
        if (dig % 2 == 0) {
            a += x * (dig / 2);
            b += x * (dig / 2);
        } else {
            if (flag) {
                a += x * (dig / 2);
                b += x * ((dig + 1) / 2);
            } else {
                a += x * ((dig + 1) / 2);
                b += x * (dig / 2);
            }
            flag = !flag;
        }
        n /= 10;
        x *= 10;
    }
    cout << a << " " << b << nl;
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

