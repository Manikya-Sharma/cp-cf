#include <iostream>
using namespace std;
 
int main() {
    string n;
    cin >> n;
    for (int i = 0; i < n.size(); i++) {
        if (i != 0 && n[i] >= '5')
            n[i] = 9 - (n[i] - '0') + '0';
    }
    int flag = 0;
    for (int i = 0; i < n.size(); i++) {
        if (!flag && n[i] == '0')
            continue;
        flag = 1;
        cout << n[i];
    }
    if (!flag) {
        // nothing printed, it is a series of nines
        cout << '9';
        for (int i=0; i<n.size()-1; i++) {
            cout << '0';
        }
    }
    return 0;
}
