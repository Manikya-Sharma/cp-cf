#include <iostream>
using namespace std;

int main() {
    int row = 0, col = 0, flag = 0;
    for (int i = 0; i < 5; i++) {
        if (!flag)
            col = 0;
        for (int j = 0; j < 5; j++) {
            int n;
            cin >> n;
            if (n == 1)
                flag = 1;
            if (!flag)
                col++;
        }
        if (!flag)
            row++;
    }
    int ans = abs(2 - row) + abs(2 - col);
    cout << ans;
    return 0;
}
