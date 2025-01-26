#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())

void solution_fn() {
    vector<int> a(2), b(2);
    cin >> a[0] >> a[1];
    cin >> b[0] >> b[1];
    int won = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            int pick1 = a[i];
            int pick2 = a[!i];
            int pick3 = b[j];
            int pick4 = b[!j];
            if (pick1 >= pick3 && pick2 >= pick4) {
                if (pick1 > pick3 || pick2 > pick4) {
                    won++;
                }
            }
        }
    }
    cout << won << nl;
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
