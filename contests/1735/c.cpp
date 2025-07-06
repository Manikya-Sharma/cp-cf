/* *** PROBLEM: 1735_c_phase_shift
ON: 2025-06-15
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

bool valid(map<char, char> &mp, char from, char to) {
    if (from == to)
        return false;
    mp[from] = to;
    char curr = to;
    int len = 0;
    while (mp.count(curr)) {
        curr = mp[curr];
        len++;
        if (curr == to) {
            mp.erase(from);
            return len == 26;
        }
    }
    mp.erase(from);
    return true;
}

void solution_fn() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, char> mp;
    set<char> taken;
    for (auto &ch : s) {
        if (mp.count(ch))
            continue;
        for (char take = 'a'; take <= 'z'; take++) {
            if (taken.count(take))
                continue;
            if (valid(mp, ch, take)) {
                mp[ch] = take;
                taken.insert(take);
                break;
            }
        }
    }
    for (auto &ch : s) {
        ch = mp[ch];
    }
    cout << s << nl;
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

