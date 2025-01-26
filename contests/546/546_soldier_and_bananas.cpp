#include <bits/stdc++.h>

using namespace std;

int main() {
    int k, n, w;
    cin >> k >> n >> w;
    long long req = k * w * (w + 1) / 2;
    cout << max(0ll, req - n) << '\n';
    return 0;
}
