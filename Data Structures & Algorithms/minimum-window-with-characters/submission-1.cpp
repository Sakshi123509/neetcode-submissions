class Solution {
   public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size(), cnt = 0, minlen = INT_MAX, st = 0;
        int hash[256] = {0};
        for (int i = 0; i < m; i++) hash[t[i]]++;
        int l = 0, r = 0;
        if (m > n) return "";
        while (r < n) {
            if (hash[s[r]] > 0) cnt++;
            hash[s[r]]--;

            // shrinking
            while (cnt == m) {
                hash[s[l]]++;
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    st = l;
                }
                if (hash[s[l]] > 0) {
                    cnt--;
                }
                l++;
            }
            r++;
        }
        return (minlen == INT_MAX) ? "" : s.substr(st, minlen);
    }
};
