#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;

void solution_fn() {
    string s;
    cin >> s;
    if (s.size() == 1) {
        cout << s[0] << (s[0] == 'a' ? 'b' : (char)(s[0] - 1)) << nl;
        return;
    }
    string output;
    output.push_back(s[0]);
    int flag = 0;
    for (int i = 1; i < s.size(); i++) {
        if (!flag && s[i] == s[i - 1]) {
            flag = 1;
            output.push_back(s[i] == 'a' ? 'b' : s[i] - 1);
        }
        output.push_back(s[i]);
    }
    if (!flag) {
        output.push_back(output[output.size() - 1] == 'a'
                             ? 'b'
                             : output[output.size() - 1] - 1);
    }
    cout << output << nl;
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
