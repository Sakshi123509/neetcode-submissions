class Solution {
    bool search(vector<int>& nums, int target) {
        int n = nums.size(), low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return true;
            else if (target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return false;
    }

   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int top = 0, bottom = n - 1;
        while (top <= bottom) {
            int midrow = top + (bottom - top) / 2;
            if (target >= matrix[midrow][0] && target <= matrix[midrow][m - 1])
                return search(matrix[midrow], target);
            else if (target > matrix[midrow][m - 1])  // column me
                top = midrow + 1;
            else
                bottom = midrow - 1;
        }
        return false;
    }
};
