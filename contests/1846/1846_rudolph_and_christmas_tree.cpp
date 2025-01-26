#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())

void solution_fn() {
    int n, d, h;
    cin >> n >> d >> h;
    vector<int> y(n);
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }
    ld area = 0;
    for (int i = 0; i < n - 1; i++) {
        if (y[i] + h > y[i + 1]) {
            area +=
                (0.5l) * d * h * (1 - pow((y[i] - y[i + 1] + h) / (ld)h, 2));
        } else {
            area += (0.5l) * d * h;
        }
    }
    // for the last branch
    area += 0.5l * d * h;
    cout << std::setprecision(15) << area << nl;
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
