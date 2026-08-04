class Solution {
   public:
    bool isIsomorphic(string s, string t) {
        int hash[256] = {0}, hash_t[256] = {0};
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (hash[s[i]] != hash_t[t[i]]) {
                return false;
            }
            hash[s[i]] = i + 1;
            hash_t[t[i]] = i + 1;
        }
        return true;
    }
};