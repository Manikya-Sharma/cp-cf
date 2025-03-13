class Matrix {
   public:
    vector<vector<int>> arr;
    int n;
    Matrix(vector<vector<int>> inp) : arr(inp) { n = sz(inp); }
    Matrix(int size) : n(size) {
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            arr[i].resize(n);
        }
    }
    static void matmul(Matrix& m1, Matrix& m2) {
        int n = sz(m1.arr);
        Matrix temp(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0;
                for (int k = 0; k < n; k++) {
                    sum += m1.arr[i][k] * m2.arr[k][j];
                }
                temp.arr[i][j] = sum;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                m1.arr[i][j] = temp.arr[i][j];
            }
        }
    }
    static Matrix exp(Matrix& m, int n) {
        Matrix res({{1, 0}, {0, 1}});
        while (n) {
            if (n & 1) {
                matmul(res, m);
            }
            matmul(m, m);
            n >>= 1;
        }
        return res;
    }
};
