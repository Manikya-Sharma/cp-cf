#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int num_problem;
        cin >> num_problem;
        vector<int> a(num_problem);
        vector<int> b(num_problem);

        for (int i = 0; i < num_problem; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < num_problem; i++) {
            cin >> b[i];
        }

        int is_valid = false;
        int ans = 0;
        while (!is_valid) {
            is_valid = true;
            for (int i = 0; i < num_problem; i++) {
                if (a[i] > b[i]) {
                    is_valid = false;
                    a.pop_back();
                    a.push_back(b[i]);
                    sort(a.begin(), a.end());
                    ans++;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
