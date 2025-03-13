/* *** PROBLEM: 2072_d_for_wizards_the_exam_is_easy_but_i_couldnt_handle_it
ON: 2025-03-09
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
    int max_dif = 0;
    pair<int, int> ans = {1, 1};
    for (int i = 0; i < n; i++) {
        int sm_count = 0;
        int lg_count = 0;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[i]) {
                sm_count++;
            } else if (a[j] > a[i]) {
                lg_count++;
            }
            if (sm_count - lg_count > max_dif) {
                max_dif = sm_count - lg_count;
                ans = {i + 1, j + 1};
            }
        }
    }
    cout << ans.first << " " << ans.second << nl;
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
