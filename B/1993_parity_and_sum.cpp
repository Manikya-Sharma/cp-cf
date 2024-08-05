#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())

void solution_fn() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    priority_queue<int> pq;
    int largest_odd = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0)
            pq.push(a[i]);
        else
            largest_odd = max(a[i], largest_odd);
    }
    if (largest_odd == 0) {
        cout << 0 << nl;
        return;
    }
    int ans = 0;
    while (!pq.empty()) {
        vector<int> store;
        while (!pq.empty() && pq.top() > largest_odd) {
            store.push_back(pq.top());
            pq.pop();
        }
        if (pq.empty()) {
            ans += store.size() + 1;
            break;
        }
        largest_odd = min(largest_odd + pq.top(), (int)1e9 + 1);
        pq.pop();
        ans++;
        for (auto elem : store) {
            pq.push(elem);
        }
    }
    cout << ans << nl;
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
