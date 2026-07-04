class Solution {
   public:
    int characterReplacement(string s, int k) {
        int n = s.size(), maxlen = INT_MIN, maxfreq = 0;
        unordered_map<int, int> mp;
        int l = 0;
        for (int r = 0; r < n; r++) {
            mp[s[r]]++;
            maxfreq = max(maxfreq, mp[s[r]]);

            // shrink
            while (((r - l + 1) - maxfreq) > k) {
                mp[s[l]]--;
                if (mp[s[l]] == 0) {
                    mp.erase(s[l]);
                }
                l++;
            }
            maxlen = max(maxlen, r - l + 1);
        }
        return maxlen;
    }
};
