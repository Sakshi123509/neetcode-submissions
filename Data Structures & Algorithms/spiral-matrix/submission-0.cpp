class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int sr = 0, sc = 0, er = n - 1, ec = m - 1;
        vector<int> ans;

        while (sr <= er && sc <= ec) {
            // right
            for (int j = sc; j <= ec; j++) {
                ans.push_back(matrix[sr][j]);
            }
            // down
            for (int i = sr + 1; i <= er; i++) {
                ans.push_back(matrix[i][ec]);
            }
            // left
            for (int j = ec - 1; j >= sc; j--) {
                if (sr == er) break;
                ans.push_back(matrix[er][j]);
            }
            // up
            for (int i = er - 1; i >= sr + 1; i--) {
                if (sc == ec) break;
                ans.push_back(matrix[i][sc]);
            }
            sc++;
            sr++;
            ec--;
            er--;
        }
        return ans;
    }
};
