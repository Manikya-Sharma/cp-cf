#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())

// TODO: Wrong answer 😢
void solution_fn() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    sort(s.begin(), s.end());

    // store the number of elements in each color
    vector<int> nums(k);
    // add single character only once, otherwise condition of palindrome is violated
    vector<bool> single_added(k);
    int i = 0;
    while (i < sz(s)) {
        // string[n] is not undefined behaviour
        if (i < sz(s) - 1 && s[i] == s[i + 1]) {
            // add this to min_idx of nums
            int min_idx = 0;
            for (int j = 0; j < k; j++) {
                if (nums[j] < nums[min_idx])
                    min_idx = j;
            }
            nums[min_idx] += 2;
            i += 2;
        } else {
            // add single element to smallest possible with availability
            int min_idx = 0;
            while (min_idx < k && single_added[min_idx])
                min_idx++;
            if (min_idx == k) {
                i++;
                continue;
            }
            for (int j = min_idx; j < k; j++) {
                if (nums[j] < nums[min_idx] && !single_added[j]) {
                    min_idx = j;
                }
            }
            single_added[min_idx] = true;
            nums[min_idx]++;
            i++;
        }
    }
    int min_val = nums[0];
    for (int x = 0; x < k; x++) {
        min_val = min(min_val, nums[x]);
    }
    // if min_val is 0, then just remove repetitions from one of the places
    cout << (min_val == 0 ? 1 : min_val) << nl;
}

int main() {
    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solution_fn();
    }
    return 0;
}
