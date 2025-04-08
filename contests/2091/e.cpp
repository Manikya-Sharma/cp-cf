/* *** PROBLEM: 2091_e_interesting_ratio
ON: 2025-03-25
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

int bs(vector<int>& primes, int i, int n) {
    int start = 0, end = sz(primes);
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (i * 1ll * primes[mid] > n) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return end;
}

void solution_fn() {
    int n;
    cin >> n;
    vector<bool> sieve(n + 1, false);
    for (int i = 2; i < n; i++) {
        if (sieve[i])
            continue;
        for (int j = i; i * 1ll * j <= n; j++) {
            sieve[j * i] = true;
        }
    }
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (!sieve[i]) {
            primes.push_back(i);
        }
    }

    ll ans = sz(primes);
    for (int i = 2; i <= n; i++) {
        int ub = bs(primes, i, n);
        ans += ub + 1;
    }
    cout << ans << nl;
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

