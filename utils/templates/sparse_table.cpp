#include <bits/stdc++.h>
using namespace std;

template <class T = int>
class SparseTable {
    vector<vector<T>> mp;
    function<T(T, T)> fn;

   public:
    SparseTable(
        vector<T>& arr,
        function<T(T, T)> fn = [](T a, T b) { return min(a, b); })
        : fn(fn) {
        int n = (int)arr.size();
        mp.assign(32 - __builtin_clzll(n), vector<T>(n));
        for (int i = 0; i < n; i++) {
            mp[0][i] = arr[i];
        }
        int w = 1;
        while ((1 << w) <= n) {
            for (int i = 0; i + (1 << w) <= n; i++) {
                mp[w][i] = fn(mp[w - 1][i], mp[w - 1][i + (1 << (w - 1))]);
            }
            w++;
        }
    }

    // Note: a and b inclusive, a <= b
    T get_range(int a, int b) {
        int w = b - a + 1;
        int k = 31 - __builtin_clzll(w);
        return fn(mp[k][a], mp[k][b - (1 << k) + 1]);
    }
};
