#include <bits/stdc++.h>
using namespace std;

void run_testcase() {
    int nums[3];
    for (int i = 0; i < 3; i++) {
        cin >> nums[i];
    }
    for (int i=0; i<5; i++) {
        // pick the smallest number
        int min_idx = 0;
        for (int j=0; j<3; j++) {
            min_idx = nums[j] < nums[min_idx] ? j : min_idx;
        }
        nums[min_idx]++;
    }
    cout << nums[0] * nums[1] * nums[2] << endl;
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        run_testcase();
    }
    return 0;
}
