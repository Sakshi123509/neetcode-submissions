class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, n = s.size(), maxlen = INT_MIN;
        unordered_map<char, int> mp;
        if (n == 0) return 0;
        while (r < n) {
            mp[s[r]]++;
            while (mp[s[r]] > 1) {
                mp[s[l]]--;
                l++;
            }
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};
