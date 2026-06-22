class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for (auto x : strs) {
            string temp = x;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(x);
        }

        for (auto word : mp) {
            ans.push_back(word.second);
        }
        return ans;
    }
};
