#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll num;
    cin >> num;
    vector<int> digits;
    while (num) {
        digits.push_back(num % 10);
        num /= 10;
    }
    for (int i = 0; i < digits.size() - 1; i++) {
        if (digits[i] >= 5)
            digits[i] = 9 - digits[i];
    }
    if (digits[digits.size() - 1] != 9 && digits[digits.size() - 1] >= 5) {
        digits[digits.size() - 1] = 9 - digits[digits.size() - 1];
    }
    for (int i = digits.size() - 1; i >= 0; i--) {
        cout << digits[i];
    }
    cout << nl;
    return 0;
}
