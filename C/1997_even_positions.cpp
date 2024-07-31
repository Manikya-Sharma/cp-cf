#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;

void solution_fn() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int op_count = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (op_count == 0) {
                s[i] = '(';
                op_count++;
            } else {
                s[i] = ')';
                op_count--;
            }
        } else {
            if (s[i] == '(')
                op_count++;
            else
                op_count--;
        }
    }

    stack<int> st;
    int cost = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(')
            st.push(i);
        else {
            int top = st.top();
            st.pop();
            cost += i - top;
        }
    }
    cout << cost << nl;
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
