#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())

// TODO: TLE
void solution_fn() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        char inp;
        cin >> inp;
        a[i] = inp - '0';
    }
    vector<int> prefixSum(n + 1);
    prefixSum[0] = 0;
    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i - 1] + a[i - 1];
    }
    int count = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (prefixSum[j] - prefixSum[i] == j - i) {
                count++;
            }
        }
    }
    cout << count << nl;
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
