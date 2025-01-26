#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;

void solution_fn() {
    ll num;
    cin >> num;
    int n = 0, arr[18];
    while (num) {
        arr[n] = num % 10;
        n++;
        num /= 10;
    }
    // units place can be any number from 0 to 8
    if (arr[0] == 9) {
        cout << "NO" << nl;
        return;
    }
    // last place must be one
    if (arr[n - 1] != 1) {
        cout << "NO" << nl;
        return;
    }
    // all other places must be from 1 to 9
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] == 0) {
            cout << "NO" << nl;
            return;
        }
    }
    cout << "YES" << nl;
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
