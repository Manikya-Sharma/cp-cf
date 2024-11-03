#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

// TODO: WA
void solution_fn() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << 1 << nl;
        return;
    }
    if (n == 2) {
        cout << a[1] - a[0] << nl;
        return;
    }
    priority_queue<ll> pq;
    for (int i = 0; i < n - 1; i++) {
        pq.push(a[i + 1] - a[i]);
    }
    for (int i = 0; i < (n % 2 == 1 ? n / 2 : n / 2 - 1); i++) {
        pq.pop();
    }
    cout << pq.top() << nl;
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
