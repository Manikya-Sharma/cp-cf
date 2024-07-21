#include <bits/stdc++.h>
using namespace std;

void solution_fn() {
    int n;
    cin >> n;
    char* seq = new char[n];
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }
    // combine all zeros to a single zero
    vector<char> reduced_seq;
    reduced_seq.push_back(seq[0]);
    for (int i = 1; i < n; i++) {
        if (seq[i] == '0' && seq[i - 1] == '0')
            continue;
        reduced_seq.push_back(seq[i]);
    }

    // now 1 only need to be majority
    int one_count = 0, zero_count = 0;
    for (auto elem : reduced_seq) {
        if (elem == '1')
            one_count++;
        else
            zero_count++;
    }
    if (one_count > zero_count) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solution_fn();
    }
    return 0;
}
