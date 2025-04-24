/* *** PROBLEM: 2093_d_skibidi_table
ON: 2025-04-08
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

ll find_val(ll a, ll b, ll n) {
    if (n == 1)
        return 1;
    ll x = (n / 2) * (n / 2);
    ll q = x;
    ll r = 2 * x;
    ll s = 3 * x;
    if (a < n / 2 && b < n / 2) {
        return find_val(a, b, n / 2);
    } else if (a >= n / 2 && b >= n / 2) {
        return q + find_val(a - n / 2, b - n / 2, n / 2);
    } else if (a >= n / 2 && b < n / 2) {
        return r + find_val(a - n / 2, b, n / 2);
    } else {
        return s + find_val(a, b - n / 2, n / 2);
    }
}

pair<int, int> find_pos(ll x, ll n) {
    if (n == 1)
        return {0, 0};
    ll y = (n / 2) * (n / 2);
    ll p = 0;
    ll q = y;
    ll r = 2 * y;
    ll s = 3 * y;
    if (x >= p && x <= q) {
        auto sub_pos = find_pos(x, n / 2);
        return sub_pos;
    } else if (x >= q && x <= r) {
        auto sub_pos = find_pos(x - q, n / 2);
        return {sub_pos.first + n / 2, sub_pos.second + n / 2};
    } else if (x >= r && x <= s) {
        auto sub_pos = find_pos(x - r, n / 2);
        return {sub_pos.first + n / 2, sub_pos.second};
    } else {
        auto sub_pos = find_pos(x - s, n / 2);
        return {sub_pos.first, sub_pos.second + n / 2};
    }
}

void solution_fn() {
    ll n, q;
    cin >> n >> q;
    string temp;
    getline(cin, temp);
    n = (1 << n);
    while (q--) {
        string inp;
        getline(cin, inp);
        if (inp[0] == '-') {
            inp = inp.substr(3, sz(inp) - 3);
            stringstream ss(inp);
            ll a, b;
            ss >> a >> b;
            cout << find_val(a - 1, b - 1, n) << nl;
        } else {
            inp = inp.substr(3, sz(inp) - 3);
            stringstream ss(inp);
            ll x;
            ss >> x;
            auto ans = find_pos(x, n);
            cout << ans.first + 1 << " " << ans.second + 1 << nl;
        }
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

