/* *** PROBLEM: 2078_d_scammy_game_ad
ON: 2025-03-10
BY: Manikya
*** */

#include <bits/stdc++.h>
using namespace std;

/* *** TEMPLATE *** */

const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define sz(x) int((x).size())

/* *** DEBUG *** */

#ifdef LOCAL
#include "/home/manikya/programming/c/cp/cf/utils/header.h"
#else
#define debug(...) ;
#endif

/* *** SOLUTION *** */

typedef struct {
    bool is_add;
    int val;
} Gate;

Gate getGate(string line, int& start) {
    bool is_add;
    if (line[start] == '+') {
        is_add = true;
    } else {
        assert(line[start] == 'x');
        is_add = false;
    }
    start += 2;
    int num = 0;
    while (start < sz(line) && line[start] != ' ') {
        num = num * 10 + line[start] - '0';
        start++;
    }
    return {is_add, num};
}

void solution_fn() {
    int n;
    cin >> n;
    vector<pair<Gate, Gate>> vpi;
    while (sz(vpi) != n) {
        string line;
        getline(cin, line);
        if (line.empty())
            continue;
        int start = 0;
        Gate gate1 = getGate(line, start);
        start++;
        Gate gate2 = getGate(line, start);
        vpi.push_back({gate1, gate2});
    }
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

