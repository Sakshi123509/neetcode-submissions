class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int l = 0, r = 0;
        int n = nums1.size(), m = nums2.size();
        while (l < n && r < m) {
            if (nums1[l] <= nums2[r]) {
                ans.push_back(nums1[l]);
                l++;
            } else {
                ans.push_back(nums2[r]);
                r++;
            }
        }
        while (l < n) {
            ans.push_back(nums1[l]);
            l++;
        }
        while (r < m) {
            ans.push_back(nums2[r]);
            r++;
        }
        int total = n + m;
        if (total % 2 == 1) return ans[total / 2];

        return (ans[total / 2] + ans[total / 2 - 1]) / 2.0;
    }
};
