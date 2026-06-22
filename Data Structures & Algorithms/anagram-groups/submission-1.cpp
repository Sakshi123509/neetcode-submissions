class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for (auto word : strs) {
            string temp = word;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(word);
        }

        for (auto word : mp) {
            ans.push_back(word.second);
        }
        return ans;
    }
};
