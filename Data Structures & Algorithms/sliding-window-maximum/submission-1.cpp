class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            // k limit
            while (!dq.empty() && dq.front() <= i - k) dq.pop_front();

            // compare
            while (!dq.empty() && nums[i] >= nums[dq.back()]) dq.pop_back();

            // insert
            dq.push_back(i);

            // ans
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
