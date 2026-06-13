class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(auto x: nums){
            mp[x]++;
        }
        for(auto x:mp){
            if((x.second)>1)return true;
        }
        return false;
    }
};