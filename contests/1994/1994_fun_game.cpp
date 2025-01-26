#include <iostream>
using namespace std;

int main() {

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        if (s == t) {
            cout << "Yes\n";
            continue;
        }
        int i = 0;
        while (i < n) {
            if (s[i] == '1') {
                break;
            }
            i++;
        }
        if (i == n) {
            cout << "No\n";
            continue;
        }
        int flag = 0;
        for (int j = 0; j < i; j++) {
            if (t[j] == '1') {
                flag = 1;
                break;
            }
        }
        if (flag)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    return 0;
}
