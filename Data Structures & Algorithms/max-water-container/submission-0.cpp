class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int maxarea = INT_MIN;
        int l = 0, n = heights.size(), h = n - 1;
        while (l < h) {
            int len = min(heights[l], heights[h]);
            int width = h - l;
            int area = len * width;
            maxarea = max(maxarea, area);
            if (heights[l] < heights[h])
                l++;
            else
                h--;
        }
        return maxarea;
    }
};
