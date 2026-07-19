class Solution {
   public:
    int dfs(int r, int c, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size(), ans = 0;

        // outoff bound
        if (r < 0 || c < 0 || r >= n || c >= m || grid[r][c] == 0) return 1;

        if (grid[r][c] == -1) return 0;

        grid[r][c] = -1;

        return dfs(r + 1, c, grid) + dfs(r - 1, c, grid) + dfs(r, c + 1, grid) +
               dfs(r, c - 1, grid);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int perimeter = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    perimeter += dfs(i, j, grid);
                }
            }
        }
        return perimeter;
    }
};