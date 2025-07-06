/* *** PROBLEM: 2123_e_mex_count
ON: 2025-07-05
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
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }

    sort(a.begin(), a.end());
    int mx = 0;
    for (auto &elem : a) {
        if (elem == mx)
            mx++;
    }
    vector<int> prefix(mx + 1, 0);
    prefix[0] = 0;
    for (int i = 1; i <= mx; i++) {
        prefix[i] = prefix[i - 1] + freq[i - 1] - 1;
    }
    vector<int> sweep(n + 2, 0);
    for (int i = 0; i <= mx; i++) {
        int num_big = n - (upper_bound(a.begin(), a.end(), i) - a.begin());
        int num_sm = prefix[i];
        int lb = freq[i];
        int ub = freq[i] + num_big + num_sm;
        sweep[lb]++;
        sweep[ub + 1]--;
    }
    int curr = 0;
    for (int i = 0; i <= n; i++) {
        curr += sweep[i];
        cout << curr << " \n"[i == n];
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

