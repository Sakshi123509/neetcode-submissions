class NumMatrix {
   public:
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        // if (matrix.empty() || matrix[0].empty()) return;

        int n = matrix.size(), m = matrix[0].size();
        prefix.resize(n, vector<int>(m, 0));
        prefix[0][0] = matrix[0][0];

        // filling row
        for (int i = 1; i < n; i++) {
            prefix[i][0] = prefix[i - 1][0] + matrix[i][0];
        }
        // filling column
        for (int j = 1; j < m; j++) {
            prefix[0][j] = prefix[0][j - 1] + matrix[0][j];
        }

        // remaining
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                prefix[i][j] =
                    matrix[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int r1, int c1, int r2, int c2) {
        // base case
        if (r1 == 0 && c1 == 0) {
            return prefix[r2][c2];
        } else if (r1 == 0) {
            return prefix[r2][c2] - prefix[r2][c1 - 1];
        } else if (c1 == 0) {
            return prefix[r2][c2] - prefix[r1 - 1][c2];
        } else
            return prefix[r2][c2] - prefix[r1 - 1][c2] - prefix[r2][c1 - 1] +
                   prefix[r1 - 1][c1 - 1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */