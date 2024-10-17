#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

// TODO: TLE
void solution_fn() {
    int n, x;
    cin >> n >> x;
    vi a(n);
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }
    sort(a.begin(), a.end());
    int mex = 0, mex_j = 0;
    while (true) {
        for (int i = mex_j; i < n; i++) {
            if (a[i] == mex) {
                mex++;
                mex_j = i;
            }
        }
        int temp = mex - x;
        bool flag = 0;
        while (temp > 0) {
            if (freq[temp] > 1) {
                mex++;
                flag = 1;
                break;
            }
            temp -= x;
        }
        if (!flag)
            break;
    }
    cout << mex << nl;
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
