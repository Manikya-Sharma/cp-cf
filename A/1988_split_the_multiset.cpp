#include <bits/stdc++.h>
using namespace std;

void solution_fn() {
    int n, k;
    cin >> n >> k;
    cout << ceil((double)(n - 1) / (k - 1)) << '\n';
}

int main() {
    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solution_fn();
    }
    return 0;
}
