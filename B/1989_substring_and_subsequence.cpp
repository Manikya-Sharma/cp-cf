#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;

void solution_fn() {
    string a, b;
    cin >> a >> b;
    int max_len = 0;
    for (int i = 0; i < b.size(); i++) {
        int ptr = i;
        for (int j = 0; j < a.size(); j++) {
            if (b[ptr] == a[j]) {
                ptr++;
            }
        }
        max_len = max(max_len, ptr - i);
    }
    cout << (a.size() + b.size() - max_len) << nl;
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
