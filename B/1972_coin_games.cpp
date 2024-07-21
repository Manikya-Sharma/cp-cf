#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        string seq;
        cin >> seq;

        int count = 0;
        for (int j = 0; j < n; j++) {
            if (seq[j] == 'U')
                count++;
        }
        if (count % 2)
            cout << "YES";
    }
    return 0;
}
