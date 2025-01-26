#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;

void solution_fn() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    // first pass
    int score1 = 0;
    int score2 = 0;
    vector<bool> visited(n);
    for (int i = 0; i < a.size(); i++) {
        if (a[i] > b[i]) {
            score1 += a[i];
            visited[i] = true;
        } else if (a[i] < b[i]) {
            score2 += b[i];
            visited[i] = true;
        } else if (a[i] == 0) {
            visited[i] = true;
        }
    }
    // secind pass: greedily remove the score
    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;
        if (a[i] == -1) {
            if (score1 > score2)
                score1--;
            else
                score2--;
        } else {
            if (score1 > score2)
                score2++;
            else
                score1++;
        }
    }
    cout << min(score1, score2) << nl;
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
