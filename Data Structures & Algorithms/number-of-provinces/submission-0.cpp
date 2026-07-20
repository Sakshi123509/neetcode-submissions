class Solution {
    void dfs(int node, vector<bool>& vis, vector<vector<int>>& grid) {
        vis[node] = true;
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            if (!vis[i] && grid[node][i] == 1) {
                dfs(i, vis, grid);
            }
        }
    }

   public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, false);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i, vis, isConnected);
            }
        }
        return cnt;
    }
};