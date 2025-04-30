/* *** PROBLEM: 2104_d_array_and_gcd
ON: 2025-04-28
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
    sort(a.begin(), a.end());
    vector<ll> suff(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        suff[i] = suff[i + 1] + a[i];
    }
    vector<int> primes;
    vector<bool> sieve(80 * n, true);
    for (int i = 2; i < sz(sieve); i++) {
        if (!sieve[i])
            continue;
        for (ll j = i; i * j < sz(sieve); j++) {
            sieve[i * j] = false;
        }
    }
    int i = 2;
    while (sz(primes) < n) {
        if (sieve[i]) {
            primes.push_back(i);
        }
        i++;
    }
    vector<ll> prefix(n + 1, 0);
    for (int j = 1; j <= n; j++) {
        prefix[j] = prefix[j - 1] + primes[j - 1];
    }
    i = 0;
    while (i < n) {
        if (suff[i] >= prefix[n - i]) {
            break;
        }
        i++;
    }
    cout << i << nl;
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

