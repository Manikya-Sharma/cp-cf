#include <bits/stdc++.h>
using namespace std;

void solution_fn() {
    int n, k;
    cin >> n >> k;
    int* pieces = new int[k];
    for (int i = 0; i < k; i++) {
        cin >> pieces[i];
    }

    int max_idx = 0;
    for (int i=0; i<k; i++) {
        if (pieces[i] > pieces[max_idx]) {
             max_idx = i;
        }
    }

    int cost = 0;
    for (int i=0; i<k; i++) {
        if (i==max_idx) continue;
        cost += 2*pieces[i] - 1;
    }
    cout << cost << "\n";
    
    delete[] pieces;
}

int main() {
    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solution_fn();
    }
    return 0;
}
