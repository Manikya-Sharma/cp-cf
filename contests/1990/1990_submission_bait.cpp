#include <bits/stdc++.h>
using namespace std;

void solution_fn() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }
    for (auto elem : mp) {
        if (elem.second % 2 == 1) {
            cout << "Yes\n";
            delete[] arr;
            return;
        }
    }
    cout << "No\n";
    delete[] arr;
}

int main() {
    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solution_fn();
    }
    return 0;
}
