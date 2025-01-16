#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>

class FenwickTree {
    int n;
    vector<int> fen;

    long long get(int idx) {
        long long sum = 0;
        while (idx > 0) {
            sum += fen[idx];
            idx -= (-idx) & idx;
        }
        return sum;
    }

   public:
    FenwickTree(vector<int>& arr) {
        n = (int)arr.size() + 1;
        fen.resize(n);
        for (int i = 0; i < (int)arr.size(); i++) {
            update(i, arr[i]);
        }
    }
    void update(int idx, int delta) {
        // 1-based
        idx++;
        while (idx < n) {
            fen[idx] += delta;
            idx += (-idx) & idx;
        }
    }

    // a and b inclusive
    long long get_range(int a, int b) { return get(b + 1) - get(a); }
};
