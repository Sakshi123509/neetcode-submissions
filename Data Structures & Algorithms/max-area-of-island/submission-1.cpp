class Solution {
   public:
    int dfs(int r, int c, vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;

        if (r < 0 || c < 0 || r >= n || c >= m || grid[r][c] == 0) return 0;
        if (grid[r][c] == 1) ans = 1;
        grid[r][c] = 0;

        ans +=
            dfs(r + 1, c, grid) + dfs(r - 1, c, grid) + dfs(r, c + 1, grid) + dfs(r, c - 1, grid);
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int maxarea = 0;

        int area = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    area = dfs(i, j, grid);
                    cout << area << " ";
                    maxarea = max(maxarea, area);
                }
            }
        }
        return maxarea;
    }
};
