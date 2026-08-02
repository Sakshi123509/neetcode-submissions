class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();

        if (s1.size() > s2.size()) return false;
        vector<int> f1(26, 0);
        vector<int> f2(26, 0);
        for (auto x : s1) f1[x - 'a']++;

        for (int i = 0; i < m; i++) {
            f2[s2[i] - 'a']++;
            if (i >= s1.size()) f2[s2[i - s1.size()] - 'a']--;
            if (f1 == f2) return true;
        }
        return false;
    }
};
