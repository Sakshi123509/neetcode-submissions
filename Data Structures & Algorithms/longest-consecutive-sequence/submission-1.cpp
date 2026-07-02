class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        int maxlen = INT_MIN;
        unordered_set<int> st(nums.begin(), nums.end());
        for (auto x : st) {
            if (st.count(x)) {
                int curr = x - 1, len = 0;
                while (st.count(curr + 1)) {
                    curr++;
                    len++;
                }
                maxlen = max(maxlen, len);
            }
        }
        return (maxlen == INT_MIN) ? 0 : maxlen;
    }
};