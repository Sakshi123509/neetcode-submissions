class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalsum=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size(),leftsum=0,rightsum=0;
        for(int i=0;i<n;i++){
            rightsum=totalsum-leftsum-nums[i];
            if(leftsum==rightsum)return i;
            leftsum+=nums[i];
        }
        return -1;
    }
};