#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;

void solution_fn() {
    int n, k;
    cin >> n >> k;
    int diag_occ = 0;
    int diag_elems = n;
    bool flag = 1;
    while (k != 0 && diag_elems > 0) {
        diag_occ++;
        if (diag_elems < k) {
            k -= diag_elems;
        } else {
            break;
        }
        if (flag)
            diag_elems -= 1;
        flag = !flag;
    }
    cout << diag_occ << nl;
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
