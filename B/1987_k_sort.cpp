#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;

void solution_fn() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int max_till_now = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] < max_till_now) {
            arr[i] = max_till_now - arr[i];
        } else {
            max_till_now = arr[i];
            arr[i] = 0;
        }
    }
    ll cost = 0;
    int max_op = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > arr[max_op])
            max_op = i;
        cost += arr[i];
    }
    cost += arr[max_op];
    cout << cost << endl;
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
